#include "big_decimal.h"

int s21_is_equal_big(s21_big_decimal num1, s21_big_decimal num2) {
  return sample_compare_big(num1, num2, IS_EQUAL_PARAMETR);
}
int s21_is_greater_or_equal_big(s21_big_decimal num1, s21_big_decimal num2) {
  return sample_compare_big(num1, num2, IS_GREATER_OR_EQUAL_PARAMETR);
}
int s21_is_greater_big(s21_big_decimal num1, s21_big_decimal num2) {
  return sample_compare_big(num1, num2, IS_GREATER_PARAMETR);
}
int s21_is_less_or_equal_big(s21_big_decimal num1, s21_big_decimal num2) {
  return sample_compare_big(num1, num2, IS_LESS_OR_EQUAL_PARAMETR);
}
int s21_is_less_big(s21_big_decimal num1, s21_big_decimal num2) {
  return sample_compare_big(num1, num2, IS_LESS_PARAMETR);
}
int s21_is_not_equal_big(s21_big_decimal num1, s21_big_decimal num2) {
  return sample_compare_big(num1, num2, IS_NOT_EQUAL_PARAMETR);
}