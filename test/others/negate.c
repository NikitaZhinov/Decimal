#include "others.h"

START_TEST(negate_1) {
  s21_decimal num = {{0, 0, 10, 0b00000000000000110000000000000000}};
  s21_decimal ex_result = {{0, 0, 10, 0b10000000000000110000000000000000}};
  s21_decimal res = {{0}};

  int exepted_result = 1, real_result = 0;

  s21_negate(num, &res);

  for (int i = 0; i <= NUM_OF_MANTISSA_BITS; i++) {
    real_result = (ex_result.bits[i] == res.bits[i]);
  }

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(negate_2) {
  s21_decimal num = {{0, 1, 0, 0b10000000000000110000000000000000}};
  s21_decimal ex_result = {{0, 1, 0, 0b00000000000000110000000000000000}};
  s21_decimal res = {{0}};

  int exepted_result = 1, real_result = 0;

  s21_negate(num, &res);

  for (int i = 0; i <= NUM_OF_MANTISSA_BITS; i++) {
    real_result = (ex_result.bits[i] == res.bits[i]);
  }

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

Suite *negate_suite_create(void) {
  Suite *suite = suite_create("negate");
  TCase *tcase_core = tcase_create("Core of negate");

  tcase_add_test(tcase_core, negate_1);
  tcase_add_test(tcase_core, negate_2);

  suite_add_tcase(suite, tcase_core);

  return suite;
}