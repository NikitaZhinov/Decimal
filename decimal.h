#ifndef _DECIMAL_H
#define _DECIMAL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  uint32_t bits[4];
} decimal;

typedef struct {
  uint32_t bits[7];
} big_decimal;

#define SIZE_BIT 32
#define COUNT_BITS_BIG_DECIMAL 7
#define NUM_OF_MANTISSA_BITS 3
#define OK 0
#define SIZE_BIT 32
#define BIG_NUM 1

#define MAX_SCALE 28 << 16  // 10^28

int get_sign(decimal num);  // получить бит знака
void set_sign(decimal *num, int sign_value);
int get_scale(decimal num);  // получить бит основания
void set_scale(decimal *num, int scale_value);
int get_bit(decimal num, int bit);  // получить бит по позиции
void set_bit(decimal *num, int bit, unsigned value);

#include "arithmetic/arithmetic.h"
#include "big_decimal/big_decimal.h"
#include "compares/compares.h"
#include "converting/converting.h"
#include "others/others.h"

#endif  //_DECIMAL_H
