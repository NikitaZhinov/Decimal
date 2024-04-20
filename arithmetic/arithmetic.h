#ifndef _ARITHMETIC
#define _ARITHMETIC

#include <stdlib.h>

#include "../decimal.h"

// errors codes
#define OK 0
#define BIG_NUM 1
#define LITTLE_NUM 2
#define DIV_BY_ZERO 3

#define NUM_OF_MANTISSA_BITS 3  // the number of stacks of bits in the mantissa
#define SIZE_BIT 32             // the size of the stack of bits
#define NUM_OF_BITS 32 * 3

int add(decimal value_1, decimal value_2, decimal *result);
int sub(decimal value_1, decimal value_2, decimal *result);
int mul(decimal value_1, decimal value_2, decimal *result);
int div(decimal value_1, decimal value_2, decimal *result);

int add_big(big_decimal value_1, big_decimal value_2,
                big_decimal *result);
int sub_big(big_decimal value_1, big_decimal value_2,
                big_decimal *result);
int mul_big(big_decimal value_1, big_decimal value_2,
                big_decimal *result);
int div_big(big_decimal value_1, big_decimal value_2,
                big_decimal *result);

void simple_add(big_decimal number_1, big_decimal number_2,
                big_decimal *result);         // addition of mantissas
int mul_by_10(big_decimal *number, int exp);  // multiplying a number by 10
int move_bits_left(big_decimal *number,
                   int n);  // shifting bits to the left
bool check_bits(big_decimal number,
                int n);  // checking bits for multiplication
void scale_alignment(big_decimal *number_1,
                     big_decimal *number_2);  // scale alignment
int max(int x, int y);
void simple_sub(big_decimal number_1, big_decimal number_2,
                big_decimal *result);
void to_empty(decimal *number);
void to_empty_big(big_decimal *number);
int move_bits_right(big_decimal *number,
                    int n);  // shift the bits to the right
big_decimal simple_div(big_decimal num1, big_decimal num2,
                           big_decimal *res);
bool is_great_decimal(big_decimal number);
void copy_from_big_decimal_to_decimal(big_decimal big, decimal *num);
bool is_zero(decimal num);
bool is_zero_big(big_decimal num);
int round_number(big_decimal *number, int scale, int sign);

#endif  // _ARITHMETIC
