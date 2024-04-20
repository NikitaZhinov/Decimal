#ifndef _CONVERTING_H
#define _CONVERTING_H

#include <math.h>

#include "../s21_decimal.h"

#define MAX_DECIMAL powl(2.0, 96)
#define MIN_DECIMAL -1 * MAX_DECIMAL
#define NEAR_ZERO 1e-28
#define S21_MAX_UINT 0xFFFFFFFF
#define S21_MAX_INT 0x7FFFFFFF
#define MAX_POW 28
#define FLOAT_ACCURACY 6

#define ERROR 1
#define OK 0

#define PLUS 0
#define MINUS 1

/**
 * @brief
 *
 * @param decimal
 */
void clear_decimal(s21_decimal* decimal);
int s21_decimal_is_set_bit(s21_decimal decimal, int index);
// int s21_get_float_exp_from_string(const char* str);
// s21_decimal s21_float_string_to_decimal(const char* str);

int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);
int s21_from_int_to_decimal(int src, s21_decimal* dst);

#endif  // _CONVERTING_H