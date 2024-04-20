#ifndef _CONVERTING_H
#define _CONVERTING_H

#include <math.h>

#include "../decimal.h"

#define MAX_DECIMAL powl(2.0, 96)
#define MIN_DECIMAL -1 * MAX_DECIMAL
#define NEAR_ZERO 1e-28
#define MAX_UINT 0xFFFFFFFF
#define MAX_INT 0x7FFFFFFF
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
void clear_decimal(decimal* decimal);
int decimal_is_set_bit(decimal decimal, int index);
// int get_float_exp_from_string(const char* str);
// decimal float_string_to_decimal(const char* str);

int from_float_to_decimal(float src, decimal* dst);
int from_decimal_to_int(decimal src, int* dst);
int from_decimal_to_float(decimal src, float* dst);
int from_int_to_decimal(int src, decimal* dst);

#endif  // _CONVERTING_H