#include "compares.h"

START_TEST(is_not_equal_1) {
  decimal num1 = {{0, 0, 10, 0}};
  decimal num2 = {{0, 0, 10, 0}};
  int exepted_result = 0, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_2) {
  decimal num1 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  decimal num2 = {{0, 0, 10, 0b00000000000011100000000000000000}};
  int exepted_result = 1, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_3) {
  decimal num1 = {{0, 123, 10, 0b00000000000001100000000000000000}};
  decimal num2 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  int exepted_result = 1, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_4) {
  decimal num1 = {{0, 0, 0, 0}};
  decimal num2 = {{0, 0, 0, 0}};
  int exepted_result = 0, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_5) {
  decimal num1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111000, 0b00000000000110010000000000000000}};
  decimal num2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b00000000000111000000000000000000}};
  int exepted_result = 1, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_6) {
  decimal num1 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000111000000000000000000}};
  decimal num2 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000110100000000000000000}};
  int exepted_result = 1, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_7) {
  decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 0, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_8) {
  decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  decimal num2 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  int exepted_result = 1, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_9) {
  decimal num1 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 1, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_10) {
  decimal num1 = {
      {0, 0, 10,
       0b00000000000111010000000000000000}};  // больше указанного scale
  decimal num2 = {{0, 0, 10, 0b00000000000111010000000000000000}};
  int exepted_result = 0, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_not_equal_11) {
  decimal num1 = {
      {999, 2, 10,
       0b10000000000011010000000000000000}};  // больше указанного scale
  decimal num2 = {{55, 1, 102, 0b10000000000110010000000000000000}};
  int exepted_result = 1, real_result = is_not_equal(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

Suite *not_equal_suite_create(void) {
  Suite *suite = suite_create("Is not equal");
  TCase *tcase_core = tcase_create("Core of is not equal");

  tcase_add_test(tcase_core, is_not_equal_1);
  tcase_add_test(tcase_core, is_not_equal_2);
  tcase_add_test(tcase_core, is_not_equal_3);
  tcase_add_test(tcase_core, is_not_equal_4);
  tcase_add_test(tcase_core, is_not_equal_5);
  tcase_add_test(tcase_core, is_not_equal_6);
  tcase_add_test(tcase_core, is_not_equal_7);
  tcase_add_test(tcase_core, is_not_equal_8);
  tcase_add_test(tcase_core, is_not_equal_9);
  tcase_add_test(tcase_core, is_not_equal_10);
  tcase_add_test(tcase_core, is_not_equal_11);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
