#include "compares.h"

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return sample_compare(num1, num2, IS_NOT_EQUAL_PARAMETR);
}