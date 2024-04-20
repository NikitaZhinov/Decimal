#include "big_decimal.h"

START_TEST(is_greater_big_1) {
  big_decimal num1 = {
      {0, 0, 10100, 0, 0, 0, 0b00000000000000100000000000000000}};
  big_decimal num2 = {{0, 0, 101, 0, 0, 0, 0b00000000000000110000000000000000}};

  int exepted_result = 1, real_result = is_greater_big(num1, num2);

  // for (int i = 0; i < COUNT_BITS_BIG_DECIMAL; i++) {
  //   real_result = (num1.bits[i] == num2.bits[i]);
  // }

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(is_greater_maxscale_big_1) {
  big_decimal num = {
      {0, 0, 10100, 0, 0, 0, 0b00000000000000100000000000000000}};

  int exepted_result = -1, real_result = is_greater_maxscale_big(&num);

  // for (int i = 0; i < COUNT_BITS_BIG_DECIMAL; i++) {
  //   real_result = (num1.bits[i] == num2.bits[i]);
  // }

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

Suite *is_greater_big_suite_create(void) {
  Suite *suite = suite_create("is greater big");
  TCase *tcase_core = tcase_create("Core of is greater big");

  tcase_add_test(tcase_core, is_greater_big_1);
  tcase_add_test(tcase_core, is_greater_maxscale_big_1);
  suite_add_tcase(suite, tcase_core);

  return suite;
}