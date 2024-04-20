#ifndef _S21_DECIMAL_H
#define _S21_DECIMAL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  uint32_t bits[4];
} s21_decimal;

typedef struct {
  uint32_t bits[7];
} s21_big_decimal;

#define SIZE_BIT 32
#define COUNT_BITS_BIG_DECIMAL 7
#define NUM_OF_MANTISSA_BITS 3
#define OK 0
#define SIZE_BIT 32
#define BIG_NUM 1

#define MAX_SCALE 28 << 16  // 10^28

int get_sign(s21_decimal num);  // получить бит знака
void set_sign(s21_decimal *num, int sign_value);
int get_scale(s21_decimal num);  // получить бит основания
void set_scale(s21_decimal *num, int scale_value);
int get_bit(s21_decimal num, int bit);  // получить бит по позиции
void set_bit(s21_decimal *num, int bit, unsigned value);

#include "arithmetic/arithmetic.h"
#include "big_decimal/big_decimal.h"
#include "compares/compares.h"
#include "converting/converting.h"
#include "others/others.h"

#endif  //_S21_DECIMAL_H
