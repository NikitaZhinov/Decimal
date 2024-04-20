#include "test.h"

START_TEST(get_sign_1) {
  decimal num = {{0, 0, 0, 0b10000000000111010000000000000000}};
  int exepted_result = 1, real_result = get_sign(num);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(get_sign_2) {
  decimal num = {{0, 0, 0, 0b00000000000111010000000000000000}};
  int exepted_result = 0, real_result = get_sign(num);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(set_sign_1) {
  decimal num = {{0, 0, 0, 0b10000000000111010000000000000000}};
  set_sign(&num, 1);
  int exepted_result = 1, real_result = get_sign(num);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(set_sign_2) {
  decimal num = {{0, 0, 0, 0b10000000000111010000000000000000}};
  set_sign(&num, 0);
  int exepted_result = 0, real_result = get_sign(num);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(get_scale_1) {
  decimal num = {{0, 0, 0, 0b10000000000110010000000000000000}};
  int exepted_result = 0b11001, real_result = get_scale(num);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(set_scale_1) {
  decimal num = {{0, 0, 0, 0b10000000000000000000000000000000}};
  set_scale(&num, 0b11001);
  int exepted_result = 0b11001, real_result = get_scale(num);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(get_bit_1) {
  decimal num = {{0, 0b10000000000110010000000000000001, 0,
                  0b10000000000110010000000000000000}};
  int exepted_result = 1, real_result = get_bit(num, 32);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(set_bit_1) {
  decimal num = {{0, 0, 0, 0b10000000000110010000000000000000}};
  set_bit(&num, 32, 1);
  int exepted_result = 1, real_result = get_bit(num, 32);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

Suite *based_suite_create(void) {
  Suite *suite = suite_create("Based");
  TCase *tcase_core = tcase_create("Core of based");

  tcase_add_test(tcase_core, get_sign_1);
  tcase_add_test(tcase_core, get_sign_2);
  tcase_add_test(tcase_core, set_sign_1);
  tcase_add_test(tcase_core, set_sign_2);
  tcase_add_test(tcase_core, get_scale_1);
  tcase_add_test(tcase_core, set_scale_1);
  tcase_add_test(tcase_core, get_bit_1);
  tcase_add_test(tcase_core, set_bit_1);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
