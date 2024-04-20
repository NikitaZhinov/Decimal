#include "compares.h"

START_TEST(is_greater_or_equal1) {
  s21_decimal num1 = {{0, 0, 10, 0}};
  s21_decimal num2 = {{0, 0, 10, 0}};
  int exepted_result = 1, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal2) {
  s21_decimal num1 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b00000000000011100000000000000000}};
  int exepted_result = 1, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal3) {
  s21_decimal num1 = {{0, 123, 10, 0b00000000000001100000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  int exepted_result = 1, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal4) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  int exepted_result = 1, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal5) {
  s21_decimal num1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111000, 0b00000000000110010000000000000000}};
  s21_decimal num2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b00000000000111000000000000000000}};
  int exepted_result = 1, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal6) {
  s21_decimal num1 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000111000000000000000000}};
  s21_decimal num2 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000110100000000000000000}};
  int exepted_result = 0, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal7) {
  s21_decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 1, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal8) {
  s21_decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  int exepted_result = 0, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal9) {
  s21_decimal num1 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 1, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal10) {
  s21_decimal num1 = {
      {0, 0, 10,
       0b00000000000111010000000000000000}};  // больше указанного scale
  s21_decimal num2 = {{0, 0, 10, 0b00000000000111010000000000000000}};
  int exepted_result = 0, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_or_equal11) {
  s21_decimal num1 = {
      {999, 2, 10,
       0b10000000000011010000000000000000}};  // больше указанного scale
  s21_decimal num2 = {{55, 1, 102, 0b10000000000110010000000000000000}};
  int exepted_result = 0, real_result = s21_is_greater_or_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

Suite *is_greater_or_equal_suite_create(void) {
  Suite *suite = suite_create("Is greater or equal");
  TCase *tcase_core = tcase_create("Core of is greater or equal");

  tcase_add_test(tcase_core, is_greater_or_equal1);
  tcase_add_test(tcase_core, is_greater_or_equal2);
  tcase_add_test(tcase_core, is_greater_or_equal3);
  tcase_add_test(tcase_core, is_greater_or_equal4);
  tcase_add_test(tcase_core, is_greater_or_equal5);
  tcase_add_test(tcase_core, is_greater_or_equal6);
  tcase_add_test(tcase_core, is_greater_or_equal7);
  tcase_add_test(tcase_core, is_greater_or_equal8);
  tcase_add_test(tcase_core, is_greater_or_equal9);
  tcase_add_test(tcase_core, is_greater_or_equal10);
  tcase_add_test(tcase_core, is_greater_or_equal11);

  suite_add_tcase(suite, tcase_core);

  return suite;
}