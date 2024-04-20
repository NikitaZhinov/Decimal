#include "compares.h"

// don't check max degree of 10
void increase_scale(big_decimal *num) {
  int start_bit_scale_big = 207;
  uint32_t one_scale = 1 << 16;

  mul_by_10_big(num);

  if (get_bit_big(*num, start_bit_scale_big) == 0) {
    set_bit_big(&(*num), start_bit_scale_big, 1);
  } else {
    num->bits[COUNT_BITS_BIG_DECIMAL - 1] += one_scale;
  }
}

int comparing_with_maxscale(big_decimal *num) {
  uint32_t mask_without_sign = num->bits[COUNT_BITS_BIG_DECIMAL - 1] &
                               0b01111111111111111111111111111111;
  int result = 0;

  if ((mask_without_sign != MAX_SCALE) && (mask_without_sign != 0)) {
    mask_without_sign > MAX_SCALE ? (result = 1) : (result = -1);
  }

  return result;
}

int comparing_scales(big_decimal *num1, big_decimal *num2) {
  int result = 0;
  uint32_t mask = 0b00000000111111110000000000000000;
  uint32_t scale1 = num1->bits[COUNT_BITS_BIG_DECIMAL - 1] & mask,
           scale2 = num2->bits[COUNT_BITS_BIG_DECIMAL - 1] & mask;

  if (scale1 != scale2) {
    scale1 > scale2 ? (result = 1) : (result = -1);
  }

  return result;
}

int comparing_bits(big_decimal *num1, big_decimal *num2) {
  int result = 0;
  int count_bits = COUNT_BITS_BIG_DECIMAL - 2;  // count bytes of mantis
  int is_bits_equal = 1;

  for (int i = count_bits; is_bits_equal && (i >= 0); i--) {
    if (num1->bits[i] != num2->bits[i]) {
      is_bits_equal = 0;

      num1->bits[i] > num2->bits[i] ? (result = 1) : (result = -1);
    }
  }

  return result;
}

int comparing_sign(decimal *num1, decimal *num2) {
  int result = 0;
  int sign1 = 0, sign2 = 0;

  get_sign(*num1) == 1 ? (sign1 = -1) : (sign1 = 0);
  get_sign(*num2) == 1 ? (sign2 = -1) : (sign2 = 0);

  if (sign1 != sign2) {
    sign1 > sign2 ? (result = 1) : (result = -1);
  }

  return result;
}