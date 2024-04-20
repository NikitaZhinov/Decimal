#include "compares.h"

START_TEST(is_less1) {
  decimal num1 = {{0, 0, 10, 0}};
  decimal num2 = {{0, 0, 10, 0}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less2) {
  decimal num1 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  decimal num2 = {{0, 0, 10, 0b00000000000011100000000000000000}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less3) {
  decimal num1 = {{0, 123, 10, 0b00000000000001100000000000000000}};
  decimal num2 = {{0, 0, 10, 0b00000000000001100000000000000000}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less4) {
  decimal num1 = {{0, 0, 0, 0}};
  decimal num2 = {{0, 0, 0, 0}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less5) {
  decimal num1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111000, 0b00000000000110010000000000000000}};
  decimal num2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b00000000000111000000000000000000}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less6) {
  decimal num1 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000111000000000000000000}};
  decimal num2 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0b00000000000110100000000000000000}};
  int exepted_result = 1, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less7) {
  decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less8) {
  decimal num1 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  decimal num2 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  int exepted_result = 1, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less9) {
  decimal num1 = {{0, 0, 10, 0b00000000000110000000000000000000}};
  decimal num2 = {{0, 0, 10, 0b10000000000110000000000000000000}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less10) {
  decimal num1 = {
      {0, 0, 10,
       0b00000000000111010000000000000000}};  // больше указанного scale
  decimal num2 = {{0, 0, 10, 0b00000000000111010000000000000000}};
  int exepted_result = 0, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_less11) {
  decimal num1 = {
      {999, 2, 10,
       0b10000000000011010000000000000000}};  // больше указанного scale
  decimal num2 = {{55, 1, 102, 0b10000000000110010000000000000000}};
  int exepted_result = 1, real_result = is_less(num1, num2);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

Suite *is_less_suite_create(void) {
  Suite *suite = suite_create("Is less");
  TCase *tcase_core = tcase_create("Core of is less");

  tcase_add_test(tcase_core, is_less1);
  tcase_add_test(tcase_core, is_less2);
  tcase_add_test(tcase_core, is_less3);
  tcase_add_test(tcase_core, is_less4);
  tcase_add_test(tcase_core, is_less5);
  tcase_add_test(tcase_core, is_less6);
  tcase_add_test(tcase_core, is_less7);
  tcase_add_test(tcase_core, is_less8);
  tcase_add_test(tcase_core, is_less9);
  tcase_add_test(tcase_core, is_less10);
  tcase_add_test(tcase_core, is_less11);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
