#ifndef _COMPARES_H
#define _COMPARES_H
#include "../s21_decimal.h"

#define IS_EQUAL_PARAMETR 1
#define IS_NOT_EQUAL_PARAMETR 2
#define IS_GREATER_PARAMETR 3
#define IS_GREATER_OR_EQUAL_PARAMETR 4
#define IS_LESS_PARAMETR 5
#define IS_LESS_OR_EQUAL_PARAMETR 6

// support_funcs

// increase numerator and denominated of big_decimal's
void increase_scale(s21_big_decimal *num);
// 0 - equal, 1 - scale greater MAX_SCALE, -1 - scale less MAX_SCALE
int comparing_with_maxscale(s21_big_decimal *num);
// 0 - equal, 1 - 1th greater 2th, -1 - 2th greater 1th
int comparing_scales(s21_big_decimal *num1, s21_big_decimal *num2);
// 0 - equal, 1 - 1th greater 2th, -1 - 2th greater 1th
int comparing_bits(s21_big_decimal *num1, s21_big_decimal *num2);
// 0 - equal, 1 - 1th greater 2th, -1 - 2th greater 1th
int comparing_sign(s21_decimal *num1, s21_decimal *num2);

// s21_funcs
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

// parametrs_comparing_func
int sample_compare(s21_decimal num1, s21_decimal num2, int parametr);

// checking_conditions_func
int check_negative_conditions_signs(int parametr, int compare_signs);
int check_positive_conditions_signs(int parametr, int compare_signs);
int check_negative_conditions_bits(int parametr, int compare_bits);

#endif  // _COMPARES_H