#include "big_decimal.h"

int is_equal_big(big_decimal num1, big_decimal num2) {
  return sample_compare_big(num1, num2, IS_EQUAL_PARAMETR);
}
int is_greater_or_equal_big(big_decimal num1, big_decimal num2) {
  return sample_compare_big(num1, num2, IS_GREATER_OR_EQUAL_PARAMETR);
}
int is_greater_big(big_decimal num1, big_decimal num2) {
  return sample_compare_big(num1, num2, IS_GREATER_PARAMETR);
}
int is_less_or_equal_big(big_decimal num1, big_decimal num2) {
  return sample_compare_big(num1, num2, IS_LESS_OR_EQUAL_PARAMETR);
}
int is_less_big(big_decimal num1, big_decimal num2) {
  return sample_compare_big(num1, num2, IS_LESS_PARAMETR);
}
int is_not_equal_big(big_decimal num1, big_decimal num2) {
  return sample_compare_big(num1, num2, IS_NOT_EQUAL_PARAMETR);
}