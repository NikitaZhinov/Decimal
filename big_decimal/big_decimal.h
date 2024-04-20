#ifndef _BIG_DECIMAL_H
#define _BIG_DECIMAL_H

#include "../decimal.h"

void fill_big_decimal(decimal *num, big_decimal *big_num);
void mul_by_10_big(big_decimal *big_num);
void move_bits_left_big(big_decimal *number, int n);
void simple_add_big(big_decimal number_1, big_decimal number_2,
                    big_decimal *result);
void copy_big_decimal(big_decimal *number_1, big_decimal number_2);

// based_big
int get_bit_big(big_decimal num, int bit);
void set_bit_big(big_decimal *num, int bit, unsigned value);
int get_sign_big(big_decimal num);
void set_sign_big(big_decimal *num, int sign_value);
int get_scale_big(big_decimal num);
void set_scale_big(big_decimal *num, int scale_value);

// for comparing with maxscale
int is_greater_maxscale_big(big_decimal *big_num);

// compares
int is_equal_big(big_decimal num1, big_decimal num2);
int is_greater_or_equal_big(big_decimal num1, big_decimal num2);
int is_greater_big(big_decimal num1, big_decimal num2);
int is_less_or_equal_big(big_decimal num1, big_decimal num2);
int is_less_big(big_decimal num1, big_decimal num2);
int is_not_equal_big(big_decimal num1, big_decimal num2);

// parametrs_comparing_func
int sample_compare_big(big_decimal num1, big_decimal num2,
                       int parametr);

// only for big_decimal: 0 - equal, 1 - num1 greater num2, -1 - num2 greater
// num1
int compare_signs_big(big_decimal *num1, big_decimal *num2);

// checking_conditions_func
int check_negative_conditions_signs(int parametr, int compare_signs);
int check_positive_conditions_signs(int parametr, int compare_signs);
int check_negative_conditions_bits(int parametr, int compare_bits);

#endif  // _BIG_DECIMAL_H