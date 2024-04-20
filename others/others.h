#ifndef _OTHERS_H
#define _OTHERS_H
#include <math.h>

#include "../s21_decimal.h"

#define IS_TRUNCATE 4
#define IS_ROUND 2
#define IS_FLOOR 3

#define ERR_CALC 1

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// custing  10^n by decimal
s21_decimal exp_ten(int ten_degree);
// dividing and round result with bank rounding
int div_and_round(int parametr, s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);
// supporting - dividing remainder by 10
int div_ostatka(int parametr, int sign, s21_big_decimal *copy_10_by_degree,
                s21_big_decimal *ostatok, s21_big_decimal *zero,
                s21_big_decimal *result_big, int err);
int is_equal_zero(s21_decimal *num);

#endif  // _OTHER_H