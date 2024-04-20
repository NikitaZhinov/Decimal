#include "others.h"

s21_decimal exp_ten(int ten_degree) {
  s21_big_decimal buff = {{10, 0, 0, 0}};
  s21_decimal result = {{0}};

  if (ten_degree != 0) {
    mul_by_10(&buff, ten_degree - 1);
    copy_from_big_decimal_to_decimal(buff, &result);
  }

  return result;
}

int div_and_round(int parametr, s21_decimal value_1, s21_decimal value_2,
                  s21_decimal* result) {
  int err = OK;
  s21_big_decimal zero = {{0}}, ostatok = {{0}};
  s21_big_decimal copy_1 = {{0}}, copy_2 = {{0}};
  s21_big_decimal value_1_big = {{0}}, value_2_big = {{0}}, result_big = {{0}};

  to_empty(result);
  fill_big_decimal(&value_1, &value_1_big);
  fill_big_decimal(&value_2, &value_2_big);

  if (s21_is_equal_big(value_2_big, zero))
    *result = value_1;
  else if (is_equal_zero(&value_1)) {
    *result = value_1;
    if (get_sign(value_1))
      result->bits[NUM_OF_MANTISSA_BITS] = 0b10000000000000000000000000000000;
    else
      result->bits[NUM_OF_MANTISSA_BITS] = 0;
  } else {
    copy_big_decimal(&copy_1, value_1_big);
    copy_1.bits[6] = 0;
    copy_big_decimal(&copy_2, value_2_big);
    copy_2.bits[6] = 0;

    if (s21_is_greater_big(copy_1, copy_2)) {
      ostatok = simple_div(copy_1, copy_2, &result_big);
      if (parametr == IS_FLOOR || parametr == IS_ROUND)
        err = div_ostatka(parametr, get_sign(value_1), &copy_2, &ostatok, &zero,
                          &result_big, err);
    } else {
      if (parametr == IS_FLOOR || parametr == IS_ROUND)
        err = div_ostatka(parametr, get_sign(value_1), &copy_2, &copy_1, &zero,
                          &result_big, err);
    }

    if (err == OK) copy_from_big_decimal_to_decimal(result_big, result);

    if ((get_sign(value_1) || get_sign(value_2)) &&
        !(get_sign(value_1) && get_sign(value_2)))
      set_sign(result, 1);
  }

  return err;
}

int is_equal_zero(s21_decimal* num) {
  int result = 0;

  for (int i = 0; i < NUM_OF_MANTISSA_BITS; i++) {
    result += (num->bits[i] == 0);
  }

  if (result >= NUM_OF_MANTISSA_BITS)
    result = 1;
  else
    result = 0;

  return result;
}

int div_ostatka(int parametr, int sign, s21_big_decimal* copy_10_by_degree,
                s21_big_decimal* ostatok, s21_big_decimal* zero,
                s21_big_decimal* result_big, int err) {
  if (!s21_is_equal_big(*ostatok, *zero) && err == OK) {
    s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal ten = {{10}};
    s21_big_decimal one_tenth = {{0}};
    s21_big_decimal five = {{5, 0, 0, 0, 0, 0, 0}};

    simple_div(*copy_10_by_degree, ten, copy_10_by_degree);

    *ostatok = simple_div(*ostatok, *copy_10_by_degree, &one_tenth);

    if (parametr == IS_ROUND) {
      if (((s21_is_equal_big(five, one_tenth) &&
            !(get_bit_big(*result_big, 0))) ||
           s21_is_less_big(five, one_tenth)) &&
          (parametr == IS_ROUND))
        simple_add(one, *result_big, result_big);
    } else if ((parametr == IS_FLOOR && sign == 1) &&
               s21_is_less_big(*zero, one_tenth))
      simple_add(one, *result_big, result_big);
  }

  if (is_great_decimal(*result_big)) err = ERR_CALC;

  return err;
}
