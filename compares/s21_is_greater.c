#include "compares.h"

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  return sample_compare(num1, num2, IS_GREATER_PARAMETR);
}