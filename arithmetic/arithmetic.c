#include "arithmetic.h"

int add(decimal value_1, decimal value_2, decimal *result) {
  int err = OK;

  big_decimal number_1 = {{0}}, number_2 = {{0}}, result_big = {{0}};
  fill_big_decimal(&value_1, &number_1);
  fill_big_decimal(&value_2, &number_2);

  err = add_big(number_1, number_2, &result_big);
  if (!!result) {
    copy_from_big_decimal_to_decimal(result_big, result);
    if (is_zero(*result)) result->bits[3] = 0;
  }

  return err;
}

int sub(decimal value_1, decimal value_2, decimal *result) {
  int err = OK;

  big_decimal number_1 = {{0}}, number_2 = {{0}}, result_big = {{0}};
  fill_big_decimal(&value_1, &number_1);
  fill_big_decimal(&value_2, &number_2);

  err = sub_big(number_1, number_2, &result_big);
  if (!!result) {
    copy_from_big_decimal_to_decimal(result_big, result);
    if (is_zero(*result)) result->bits[3] = 0;
  }

  return err;
}

int mul(decimal value_1, decimal value_2, decimal *result) {
  int err = OK;

  big_decimal number_1 = {{0}}, number_2 = {{0}}, result_big = {{0}};
  fill_big_decimal(&value_1, &number_1);
  fill_big_decimal(&value_2, &number_2);

  err = mul_big(number_1, number_2, &result_big);
  if (!!result) {
    copy_from_big_decimal_to_decimal(result_big, result);
    if (is_zero(*result)) result->bits[3] = 0;
  }

  return err;
}

int decimal_div(decimal value_1, decimal value_2, decimal *result) {
  int err = OK;

  if (is_zero(value_2))
    err = DIV_BY_ZERO;
  else if (is_zero(value_1)) {
    if (!!result) to_empty(result);
  } else {
    big_decimal number_1 = {{0}}, number_2 = {{0}}, result_big = {{0}};
    fill_big_decimal(&value_1, &number_1);
    fill_big_decimal(&value_2, &number_2);

    err = div_big(number_1, number_2, &result_big);
    if (!!result) {
      copy_from_big_decimal_to_decimal(result_big, result);
      if (is_zero(*result)) result->bits[3] = 0;
    }
  }

  return err;
}

int add_big(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  to_empty_big(result);

  int err = OK;

  scale_alignment(&value_1, &value_2);

  int sign_res = 0;

  if (!get_sign_big(value_1) && !get_sign_big(value_2)) {
    simple_add(value_1, value_2, result);  // 1 + 2
    err = round_number(result, get_scale_big(value_1), sign_res);
  } else if (get_sign_big(value_1) && !get_sign_big(value_2)) {
    set_sign_big(&value_1, 0);
    err = sub_big(value_2, value_1, result);  // 2 - 1
  } else if (!get_sign_big(value_1) && get_sign_big(value_2)) {
    set_sign_big(&value_2, 0);
    err = sub_big(value_1, value_2, result);  // 1 - 2
  } else if (get_sign_big(value_1) && get_sign_big(value_2)) {
    simple_add(value_1, value_2, result);  // -(1 + 2)
    sign_res = 1;
    err = round_number(result, get_scale_big(value_1), sign_res);
  }

  return err;
}

int sub_big(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  to_empty_big(result);

  scale_alignment(&value_1, &value_2);

  int sign_res = 0;

  if (!get_sign_big(value_1) && !get_sign_big(value_2)) {
    if (is_less_big(value_2, value_1))  // 1 > 2 -> 1 - 2
      simple_sub(value_1, value_2, result);
    else {  // 1 < 2 -> -(2 - 1)
      simple_sub(value_2, value_1, result);
      sign_res = 1;
    }
  } else if (get_sign_big(value_1) &&
             get_sign_big(value_2)) {  // -1 - -2 -> 2 - 1
    set_sign_big(&value_1, 0);
    set_sign_big(&value_2, 0);

    if (is_less_big(value_1, value_2))  // |1| < |2| -> 2 - 1
      simple_sub(value_2, value_1, result);
    else {  // |1| > |2| -> -(1 - 2)
      simple_sub(value_1, value_2, result);
      sign_res = 1;
    }
  } else if (get_sign_big(value_1) &&
             !get_sign_big(value_2)) {  // -1 - 2 -> -(1 + 2)
    simple_add(value_1, value_2, result);
    sign_res = 1;
  } else if (!get_sign_big(value_1) &&
             get_sign_big(value_2)) {  // 1 - -2 -> 1 + 2
    simple_add(value_1, value_2, result);
  }

  set_scale_big(result, get_scale_big(value_1));

  int err = round_number(result, get_scale_big(*result), sign_res);
  return err;
}

int mul_big(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  to_empty_big(result);

  int sign_res = 0;

  for (int i = 0; i < (COUNT_BITS_BIG_DECIMAL - 1) * SIZE_BIT; i++) {
    if (get_bit_big(value_2, i)) {
      big_decimal n = {{0}};
      n = value_1;
      move_bits_left(&n, i);
      simple_add(*result, n, result);
    }
  }

  if ((!get_sign_big(value_1) && get_sign_big(value_2)) ||
      (get_sign_big(value_1) && !get_sign_big(value_2)))
    sign_res = 1;

  int err = round_number(
      result, get_scale_big(value_1) + get_scale_big(value_2), sign_res);
  return err;
}

int div_big(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  to_empty_big(result);

  int sign_res = 0;

  if ((get_sign_big(value_1) || get_sign_big(value_2)) &&
      !(get_sign_big(value_1) && get_sign_big(value_2)))
    sign_res = 1;

  set_sign_big(&value_1, 0);
  set_sign_big(&value_2, 0);

  // increasing the mantissa of the first number
  big_decimal copy_1, copy_2;
  copy_1 = value_1;
  copy_1.bits[6] = 0;
  copy_2 = value_2;
  copy_2.bits[6] = 0;
  while (is_less_big(copy_1, copy_2)) {
    mul_by_10(&value_1, 1);
    set_scale_big(&value_1, get_scale_big(value_1) + 1);
    copy_1 = value_1;
    copy_1.bits[6] = 0;
  }

  big_decimal ostatok = simple_div(value_1, value_2, result);
  int scale_res = get_scale_big(value_1) - get_scale_big(value_2);
  if (scale_res >= 0)
    set_scale_big(result, scale_res);
  else
    mul_by_10(result, -scale_res);

  scale_res = get_scale_big(*result);
  while (!is_zero_big(ostatok) && !get_bit_big(*result, 96)) {
    big_decimal s = {{0}};
    mul_by_10(&ostatok, 1);
    mul_by_10(result, 1);
    scale_res++;
    ostatok = simple_div(ostatok, value_2, &s);
    simple_add(*result, s, result);
  }

  int err = round_number(result, scale_res, sign_res);
  return err;
}

big_decimal simple_div(big_decimal num1, big_decimal num2, big_decimal *res) {
  big_decimal copy_num2 = {{0}}, ostatok = {{0}};
  to_empty_big(res);
  num1.bits[6] = 0;
  num2.bits[6] = 0;
  do {
    int q = 0;
    copy_num2 = num2;
    while (is_less_or_equal_big(copy_num2, num1)) {
      move_bits_left(&copy_num2, 1);
      q++;
    }
    if (q > 0) {
      q--;
      move_bits_right(&copy_num2, 1);
    }
    big_decimal s = {{1}};
    move_bits_left(&s, q);
    simple_add(*res, s, res);
    simple_sub(num1, copy_num2, &ostatok);
    num1 = ostatok;
  } while (is_less_or_equal_big(num2, ostatok));
  return ostatok;
}

void simple_add(big_decimal number_1, big_decimal number_2,
                big_decimal *result) {
  int res = 0, ovf = 0;
  to_empty_big(result);
  for (int pos = 0; pos < (COUNT_BITS_BIG_DECIMAL - 1) * SIZE_BIT; pos++) {
    res = get_bit_big(number_1, pos) + get_bit_big(number_2, pos) + ovf;
    ovf = res / 2;
    set_bit_big(result, pos, res % 2);
  }
}

int mul_by_10(big_decimal *number, int exp) {
  int err = OK;
  big_decimal copy = {{0}};

  for (int i = 0; i < exp; i++) {
    if (err == OK) {
      copy = *number;

      if (err == OK) err = move_bits_left(number, 1);
      if (err == OK) err = move_bits_left(&copy, 3);

      if (err == OK) simple_add(*number, copy, number);
    }
  }
  return err;
}

int move_bits_left(big_decimal *number, int n) {
  int err = OK;

  for (int j = 0; j < n; j++) {
    for (int i = 5; i >= 0; i--) {
      int last_pos = i * SIZE_BIT + 31;
      if (err == OK) {
        if (!get_bit_big(*number, last_pos))
          number->bits[i] <<= 1;
        else if (i == 5)
          err = BIG_NUM;
        else {
          set_bit_big(number, last_pos + 1, 1);
          number->bits[i] <<= 1;
        }
      }
    }
  }

  return err;
}

void scale_alignment(big_decimal *number_1, big_decimal *number_2) {
  int scale_1 = get_scale_big(*number_1);
  int scale_2 = get_scale_big(*number_2);
  int sign_1 = get_sign_big(*number_1);
  int sign_2 = get_sign_big(*number_2);

  if (scale_1 > scale_2)
    mul_by_10(number_2, scale_1 - scale_2);
  else
    mul_by_10(number_1, scale_2 - scale_1);

  set_scale_big(number_1, max(scale_1, scale_2));
  set_scale_big(number_2, max(scale_1, scale_2));
  set_sign_big(number_1, sign_1);
  set_sign_big(number_2, sign_2);
}

int max(int x, int y) { return (x > y) ? x : y; }

void simple_sub(big_decimal number_1, big_decimal number_2,
                big_decimal *result) {
  to_empty_big(result);
  for (int i = 0; i < COUNT_BITS_BIG_DECIMAL - 1; i++) {
    for (int j = 0; j < SIZE_BIT; j++) {
      int pos = i * SIZE_BIT + j;
      int bit_1 = get_bit_big(number_1, pos);
      int bit_2 = get_bit_big(number_2, pos);

      if (!bit_1 && bit_2) {
        int pos_ = pos + 1;
        while (!get_bit_big(number_1, pos_)) set_bit_big(&number_1, pos_++, 1);
        set_bit_big(&number_1, pos_, 0);
        set_bit_big(result, pos, 1);
      } else
        set_bit_big(result, pos, bit_1 - bit_2);
    }
  }
}

void to_empty(decimal *number) {
  for (int i = 0; i < 4; i++) number->bits[i] = 0;
}

void to_empty_big(big_decimal *number) {
  for (int i = 0; i < COUNT_BITS_BIG_DECIMAL; i++) number->bits[i] = 0;
}

int move_bits_right(big_decimal *number, int n) {
  int err = OK;

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < COUNT_BITS_BIG_DECIMAL - 1; i++) {
      int first_pos = i * SIZE_BIT;
      if (err == OK) {
        if (!get_bit_big(*number, first_pos))
          number->bits[i] >>= 1;
        else if (i == 0)
          err = LITTLE_NUM;
        else {
          set_bit_big(number, first_pos - 1, 1);
          number->bits[i] >>= 1;
        }
      }
    }
  }
  return err;
}

bool is_great_decimal(big_decimal number) {
  bool res = false;
  for (int i = 3; i < COUNT_BITS_BIG_DECIMAL - 1; i++)
    if (number.bits[i] != 0) res = true;
  return res;
}

void copy_from_big_decimal_to_decimal(big_decimal big, decimal *num) {
  for (int i = 0; i < NUM_OF_MANTISSA_BITS; i++) num->bits[i] = big.bits[i];
  num->bits[3] = big.bits[6];
}

bool is_zero(decimal num) {
  bool res = true;
  for (int i = 0; i < NUM_OF_MANTISSA_BITS; i++)
    if (num.bits[i] != 0) res = false;
  return res;
}

bool is_zero_big(big_decimal num) {
  bool res = true;
  for (int i = 0; i < COUNT_BITS_BIG_DECIMAL - 1; i++)
    if (num.bits[i] != 0) res = false;
  return res;
}

int round_number(big_decimal *number, int scale, int sign) {
  int err = OK;
  if (is_great_decimal(*number)) {
    big_decimal int_part = *number;
    big_decimal ten = {{1}};
    mul_by_10(&ten, scale);

    if (is_greater_or_equal_big(int_part, ten))
      simple_div(int_part, ten, &int_part);
    else
      to_empty_big(&int_part);

    to_empty_big(&ten);
    ten.bits[0] = 10;

    if (is_great_decimal(int_part))
      err = sign == 1 ? LITTLE_NUM : BIG_NUM;
    else {
      big_decimal ost = {{0}};
      while ((is_great_decimal(*number) && scale > 0) || scale > 28) {
        ost = simple_div(*number, ten, number);
        scale--;
      }

      bool is_even = get_bit_big(int_part, 0) ? false : true;
      int fisrt_number_from_ost = 0;
      while (is_greater_or_equal_big(ost, ten)) simple_div(ost, ten, &ost);
      fisrt_number_from_ost = ost.bits[0];
      if ((is_even && fisrt_number_from_ost > 5) ||
          (!is_even && fisrt_number_from_ost > 4)) {
        big_decimal one = {{1}};
        simple_add(*number, one, number);
      }
    }
  } else if (scale > 28) {
    big_decimal ten = {{1}};
    mul_by_10(&ten, scale - 28);
    if (is_greater_or_equal_big(*number, ten))
      simple_div(*number, ten, number);
    else
      to_empty_big(number);
  }

  number->bits[6] = 0;
  set_scale_big(number, scale);
  set_sign_big(number, sign);

  return err;
}
