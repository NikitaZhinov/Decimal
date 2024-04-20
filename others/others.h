#ifndef _OTHERS_H
#define _OTHERS_H
#include <math.h>

#include "../decimal.h"

#define IS_TRUNCATE 4
#define IS_ROUND 2
#define IS_FLOOR 3

#define ERR_CALC 1

int decimal_floor(decimal value, decimal *result);
int decimal_round(decimal value, decimal *result);
int truncate(decimal value, decimal *result);
int negate(decimal value, decimal *result);

// custing  10^n by decimal
decimal exp_ten(int ten_degree);
// dividing and round result with bank rounding
int div_and_round(int parametr, decimal value_1, decimal value_2,
                  decimal *result);
// supporting - dividing remainder by 10
int div_ostatka(int parametr, int sign, big_decimal *copy_10_by_degree,
                big_decimal *ostatok, big_decimal *zero,
                big_decimal *result_big, int err);
int is_equal_zero(decimal *num);

#endif  // _OTHER_H