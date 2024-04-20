#ifndef _ARITHMETIC
#define _ARITHMETIC

#include <stdlib.h>

#include "../s21_decimal.h"

// errors codes
#define OK 0
#define BIG_NUM 1
#define LITTLE_NUM 2
#define DIV_BY_ZERO 3

#define NUM_OF_MANTISSA_BITS 3  // the number of stacks of bits in the mantissa
#define SIZE_BIT 32             // the size of the stack of bits
#define NUM_OF_BITS 32 * 3

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_add_big(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);
int s21_sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);
int s21_mul_big(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);
int s21_div_big(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);

void simple_add(s21_big_decimal number_1, s21_big_decimal number_2,
                s21_big_decimal *result);         // addition of mantissas
int mul_by_10(s21_big_decimal *number, int exp);  // multiplying a number by 10
int move_bits_left(s21_big_decimal *number,
                   int n);  // shifting bits to the left
bool check_bits(s21_big_decimal number,
                int n);  // checking bits for multiplication
void scale_alignment(s21_big_decimal *number_1,
                     s21_big_decimal *number_2);  // scale alignment
int max(int x, int y);
void simple_sub(s21_big_decimal number_1, s21_big_decimal number_2,
                s21_big_decimal *result);
void to_empty(s21_decimal *number);
void to_empty_big(s21_big_decimal *number);
int move_bits_right(s21_big_decimal *number,
                    int n);  // shift the bits to the right
s21_big_decimal simple_div(s21_big_decimal num1, s21_big_decimal num2,
                           s21_big_decimal *res);
bool is_great_decimal(s21_big_decimal number);
void copy_from_big_decimal_to_decimal(s21_big_decimal big, s21_decimal *num);
bool is_zero(s21_decimal num);
bool is_zero_big(s21_big_decimal num);
int round_number(s21_big_decimal *number, int scale, int sign);

#endif  // _ARITHMETIC
