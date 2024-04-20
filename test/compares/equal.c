#include "compares.h"

START_TEST(is_equal_1) {
  s21_decimal num1 = {{0, 0, 10, 0}};
  s21_decimal num2 = {{0, 0, 10, 0}};
  int exepted_result = 1, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_2) {
  s21_decimal num1 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b00000000000011100000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal num1 = {{0, 123, 10, 0b00000000000001100000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_4) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  int exepted_result = 1, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_5) {
  s21_decimal num1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111000, 0b00000000000110010000000000000000}};
  s21_decimal num2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b00000000000111000000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_6) {
  s21_decimal num1 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000111000000000000000000}};
  s21_decimal num2 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000110100000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_7) {
  s21_decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 1, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_8) {
  s21_decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_9) {
  s21_decimal num1 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  s21_decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_10) {
  s21_decimal num1 = {
      {0, 0, 10,
       0b00000000000111010000000000000000}};  // больше указанного scale
  s21_decimal num2 = {{0, 0, 10, 0b00000000000111010000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_equal_11) {
  s21_decimal num1 = {
      {999, 2, 10,
       0b10000000000011010000000000000000}};  // больше указанного scale
  s21_decimal num2 = {{55, 1, 102, 0b10000000000110010000000000000000}};
  int exepted_result = 0, real_result = s21_is_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

Suite *equal_suite_create(void) {
  Suite *suite = suite_create("Equal");
  TCase *tcase_core = tcase_create("Core of equal");

  tcase_add_test(tcase_core, is_equal_1);
  tcase_add_test(tcase_core, is_equal_2);
  tcase_add_test(tcase_core, is_equal_3);
  tcase_add_test(tcase_core, is_equal_4);
  tcase_add_test(tcase_core, is_equal_5);
  tcase_add_test(tcase_core, is_equal_6);
  tcase_add_test(tcase_core, is_equal_7);
  tcase_add_test(tcase_core, is_equal_8);
  tcase_add_test(tcase_core, is_equal_9);
  tcase_add_test(tcase_core, is_equal_10);
  tcase_add_test(tcase_core, is_equal_11);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
