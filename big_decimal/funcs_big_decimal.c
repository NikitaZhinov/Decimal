#include "big_decimal.h"

void fill_big_decimal(decimal *num, big_decimal *big_num) {
  int bit_of_scale = NUM_OF_MANTISSA_BITS;
  int bit_of_scale_big_decimal = COUNT_BITS_BIG_DECIMAL - 1;

  for (int i = 0; i < NUM_OF_MANTISSA_BITS && (i != bit_of_scale); i++) {
    big_num->bits[i] = num->bits[i];
  }

  big_num->bits[bit_of_scale_big_decimal] = num->bits[bit_of_scale];
}

void mul_by_10_big(
    big_decimal *big_num) {  // don't adding one scale in big decimal
  big_decimal copy;

  copy_big_decimal(&copy, *big_num);
  move_bits_left_big(big_num, 1);
  move_bits_left_big(&copy, 3);
  simple_add_big(*big_num, copy, big_num);
}

void move_bits_left_big(big_decimal *number, int n) {
  for (int i = COUNT_BITS_BIG_DECIMAL - 2; i >= 0; i--) {
    int last_pos = (i + 1) * SIZE_BIT - 1;
    for (int j = 0; j < n; j++) {
      if (!get_bit_big(*number, last_pos))
        number->bits[i] <<= 1;
      else {
        set_bit_big(number, last_pos + 1, 1);
        number->bits[i] <<= 1;
      }
    }
  }
}

void simple_add_big(big_decimal number_1, big_decimal number_2,
                    big_decimal *result) {
  int next_bit = 0;

  for (size_t i = 0; i < COUNT_BITS_BIG_DECIMAL - 2; i++) {
    for (size_t j = 0; j < SIZE_BIT; j++) {
      size_t pos = i * SIZE_BIT + j;
      int bit_1 = get_bit_big(number_1, pos);
      int bit_2 = get_bit_big(number_2, pos);
      if (next_bit) {
        switch (bit_1 + bit_2) {
          case 0:
            next_bit = 0;
            set_bit_big(result, pos, 1);
            break;

          case 1:
            set_bit_big(result, pos, 0);
            break;

          default:
            set_bit_big(result, pos, 1);
            break;
        }
      } else if (bit_1 + bit_2 > 1) {
        next_bit = 1;
        set_bit_big(result, pos, 0);
      } else {
        next_bit = 0;
        set_bit_big(result, pos, bit_1 + bit_2);
      }
    }
  }
}

void copy_big_decimal(big_decimal *number_1, big_decimal number_2) {
  for (int i = 0; i < COUNT_BITS_BIG_DECIMAL; i++)
    number_1->bits[i] = number_2.bits[i];
}

int get_bit_big(big_decimal num, int bit) {
  return (num.bits[bit / 32] & (1 << (bit % 32))) >> (bit % 32);
}

void set_bit_big(big_decimal *num, int bit, unsigned value) {
  if (value)
    num->bits[bit / 32] |= (1 << (bit % 32));
  else
    num->bits[bit / 32] &= ~(1 << (bit % 32));
}

int get_sign_big(big_decimal num) {
  int theSign = 0x80000000;  // 0b10000000000000000000000000000000;
  int result = 0;

  uint32_t mask = 1 << 31;

  result = num.bits[COUNT_BITS_BIG_DECIMAL - 1] & mask;

  if (result == theSign) {
    result = 1;
  } else {
    result = 0;
  }

  return result;
}

void set_sign_big(big_decimal *num, int sign_value) {
  if (sign_value == 0 || sign_value == 1) {
    uint32_t mask = 1 << 31;

    if (sign_value == 0) {
      num->bits[COUNT_BITS_BIG_DECIMAL - 1] =
          num->bits[COUNT_BITS_BIG_DECIMAL - 1] << 1;
      num->bits[COUNT_BITS_BIG_DECIMAL - 1] =
          num->bits[COUNT_BITS_BIG_DECIMAL - 1] >> 1;
    } else {
      num->bits[COUNT_BITS_BIG_DECIMAL - 1] |= mask;
    }
  }
}

int get_scale_big(big_decimal num) {
  int result = 0;

  uint32_t num_copy = num.bits[COUNT_BITS_BIG_DECIMAL - 1];
  uint32_t mask = 0b0000000011111111;

  num_copy = num_copy << 1;
  num_copy = num_copy >> 17;

  result = num_copy & mask;

  return result;
}

void set_scale_big(big_decimal *num, int scale_value) {
  if (scale_value >= 0 && scale_value <= 28) {
    int sign = get_sign_big(*num);
    uint32_t bit3_copy = num->bits[COUNT_BITS_BIG_DECIMAL - 1];

    bit3_copy = bit3_copy << 1;
    bit3_copy = bit3_copy >> 17;
    uint32_t mask = 0b0000000011111111;

    bit3_copy = mask & scale_value;
    bit3_copy = bit3_copy << 16;

    num->bits[COUNT_BITS_BIG_DECIMAL - 1] = bit3_copy;
    set_sign_big(&(*num), sign);
  }
}

int is_greater_maxscale_big(big_decimal *big_num) {
  uint32_t mask_without_sign = big_num->bits[COUNT_BITS_BIG_DECIMAL - 1] &
                               0b01111111111111111111111111111111;
  int result = 0;

  if (mask_without_sign != MAX_SCALE) {
    mask_without_sign > MAX_SCALE ? (result = 1) : (result = -1);
  }

  return result;
}
