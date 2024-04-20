#include "big_decimal.h"

int sample_compare_big(big_decimal num1, big_decimal num2,
                       int parametr) {
  int compare_scales = 0;
  int compare_bits = 0;
  int compare_signs = compare_signs_big(&num1, &num2);
  int result = 1;

  compare_scales = comparing_scales(&num1, &num2);

  if ((comparing_with_maxscale(&num1) == 1) &&
      (comparing_with_maxscale(&num2) == 1))
    result = 0;
  else if (check_negative_conditions_signs(parametr, compare_signs))
    result = 0;
  else if (check_positive_conditions_signs(parametr, compare_signs))
    result = 1;

  else {
    while (compare_scales != 0 && (((comparing_with_maxscale(&num1) == -1) ||
                                    (comparing_with_maxscale(&num1) == 0)) &&
                                   ((comparing_with_maxscale(&num2) == -1) ||
                                    (comparing_with_maxscale(&num2) == 0)))) {
      compare_scales = comparing_scales(&num1, &num2);

      switch (compare_scales) {
        case 1:
          increase_scale(&num2);
          break;
        case -1:
          increase_scale(&num1);
          break;
      }
    }

    compare_bits = comparing_bits(&num1, &num2);

    if (((get_sign_big(num1) == 1) && (get_sign_big(num2) == 1)) &&
        compare_bits != 0) {
      (compare_bits == 1) ? (compare_bits = -1) : (compare_bits = 1);
    }

    if (check_negative_conditions_bits(parametr, compare_bits)) result = 0;
  }

  return result;
}

int compare_signs_big(big_decimal* num1, big_decimal* num2) {
  int sign1 = 0, sign2 = 0;
  sign1 = get_sign_big(*num1);
  sign2 = get_sign_big(*num2);
  int result = 0;

  if (sign1 != sign2) {
    (sign1 > sign2) ? (result = -1) : (result = 1);
  }

  return result;
}
