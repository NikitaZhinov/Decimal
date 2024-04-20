#include "compares.h"

int sample_compare(decimal num1, decimal num2, int parametr) {
  int compare_scales = 0;  // comparing_scales(&num1, &num2);
  int compare_bits = 0;
  int compare_signs = comparing_sign(&num1, &num2);
  int result = 1;  // assure compare is okay

  big_decimal big_num1 = {{0, 0, 0, 0, 0, 0, 0}},
              big_num2 = {{0, 0, 0, 0, 0, 0, 0}};

  fill_big_decimal(&num1, &big_num1);
  fill_big_decimal(&num2, &big_num2);

  compare_scales = comparing_scales(&big_num1, &big_num2);

  if ((comparing_with_maxscale(&big_num1) == 1) &&
      (comparing_with_maxscale(&big_num2) == 1))
    result = 0;
  else if (check_negative_conditions_signs(parametr, compare_signs))
    result = 0;
  else if (check_positive_conditions_signs(parametr, compare_signs))
    result = 1;

  else {
    while (compare_scales != 0 &&
           (((comparing_with_maxscale(&big_num1) == -1) ||
             (comparing_with_maxscale(&big_num1) == 0)) &&
            ((comparing_with_maxscale(&big_num2) == -1) ||
             (comparing_with_maxscale(&big_num2) == 0)))) {
      compare_scales = comparing_scales(&big_num1, &big_num2);

      switch (compare_scales) {
        case 1:
          increase_scale(&big_num2);
          break;
        case -1:
          increase_scale(&big_num1);
          break;
      }
    }

    compare_bits = comparing_bits(&big_num1, &big_num2);

    if (((get_sign_big(big_num1) == 1) && (get_sign_big(big_num2) == 1)) &&
        compare_bits !=
            0) {  // for comparing logic when  num1 < 0 and -num2 < 0
      (compare_bits == 1) ? (compare_bits = -1) : (compare_bits = 1);
    }

    if (check_negative_conditions_bits(parametr, compare_bits)) result = 0;
  }

  return result;
}

int check_negative_conditions_signs(int parametr, int compare_signs) {
  int result = 0;

  if (((parametr == IS_EQUAL_PARAMETR) && (compare_signs != 0)) ||
      ((parametr == IS_GREATER_PARAMETR) && (compare_signs == -1)) ||
      ((parametr == IS_GREATER_OR_EQUAL_PARAMETR) && (compare_signs == -1)) ||
      ((parametr == IS_LESS_PARAMETR) && (compare_signs == 1)) ||
      ((parametr == IS_LESS_OR_EQUAL_PARAMETR) && (compare_signs == 1))) {
    result = 1;
  }

  return result;
}

int check_positive_conditions_signs(int parametr, int compare_signs) {
  int result = 0;

  if (((parametr == IS_NOT_EQUAL_PARAMETR) && (compare_signs != 0)) ||
      (parametr == IS_LESS_PARAMETR && (compare_signs == -1)) ||
      (parametr == IS_GREATER_PARAMETR && (compare_signs == 1))) {
    result = 1;
  }

  return result;
}

int check_negative_conditions_bits(int parametr, int compare_bits) {
  int result = 0;

  if ((((parametr == IS_EQUAL_PARAMETR) && (compare_bits != 0)) ||
       ((parametr == IS_NOT_EQUAL_PARAMETR) && (compare_bits == 0))) ||
      ((parametr == IS_GREATER_PARAMETR) && (compare_bits == -1)) ||
      ((parametr == IS_GREATER_PARAMETR) && (compare_bits == 0)) ||
      ((parametr == IS_GREATER_OR_EQUAL_PARAMETR) && (compare_bits == -1)) ||
      ((parametr == IS_LESS_PARAMETR) && (compare_bits == 1)) ||
      ((parametr == IS_LESS_PARAMETR) && (compare_bits == 0)) ||
      ((parametr == IS_LESS_OR_EQUAL_PARAMETR) && (compare_bits == 1))) {
    result = 1;
  }

  return result;
}
