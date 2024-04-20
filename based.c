#include "s21_decimal.h"

int get_sign(s21_decimal num) {
  int theSign = 0b10000000000000000000000000000000;
  int result = 0;

  uint32_t mask = 1 << 31;

  result = num.bits[3] & mask;

  if (result == theSign) {
    result = 1;
  } else {
    result = 0;
  }

  return result;
}

void set_sign(s21_decimal *num, int sign_value) {
  if (sign_value == 0 || sign_value == 1) {
    uint32_t mask = 1 << 31;

    if (sign_value == 0) {
      num->bits[3] = num->bits[3] << 1;
      num->bits[3] = num->bits[3] >> 1;
    } else {
      num->bits[3] |= mask;
    }
  }
}

int get_scale(s21_decimal num) {
  int result = 0;

  uint32_t num_copy = num.bits[3];
  uint32_t mask = 0b0000000011111111;

  num_copy = num_copy << 1;  // откинуть знак
  num_copy = num_copy >> 17;

  result = num_copy & mask;

  return result;
}

void set_scale(s21_decimal *num, int scale_value) {
  if (scale_value >= 0 && scale_value <= 28) {
    int sign = get_sign(*num);
    uint32_t bit3_copy = num->bits[3];

    bit3_copy = bit3_copy << 1;
    bit3_copy = bit3_copy >> 17;
    uint32_t mask = 0b0000000011111111;

    bit3_copy = mask & scale_value;
    bit3_copy = bit3_copy << 16;

    num->bits[3] = bit3_copy;
    set_sign(&(*num), sign);
  }
}

int get_bit(s21_decimal num, int bit) {
  return (num.bits[bit / 32] & (1 << (bit % 32))) >> (bit % 32);
}

void set_bit(s21_decimal *num, int bit, unsigned value) {
  if (value)
    num->bits[bit / 32] |= (1 << (bit % 32));
  else
    num->bits[bit / 32] &= ~(1 << (bit % 32));
}

// yelvettea
