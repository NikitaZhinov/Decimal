#include "converting.h"

START_TEST(float_decimal_1) {
  // src = -19,527637101186409220326408593
  decimal exepted_res = {{1711128977, 1850023458, 1058595328, -2145714176}};
  decimal res = {{0}};
  float standart = -19.527637;

  int exepted_result = 0, real_result = 0;

  from_float_to_decimal(standart, &res);

  for (int i = 0; i <= NUM_OF_MANTISSA_BITS; i++) {
    real_result = (exepted_res.bits[i] == res.bits[i]);
  }

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(float_decimal_2) {
  float num = 23.4;

  int exepted_result = 1, real_result = from_float_to_decimal(num, NULL);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(float_decimal_3) {
  float num = 0;
  decimal res = {{0}};
  decimal ex_res = {{0}};

  int exepted_result = 0, real_result = from_float_to_decimal(num, &res);

  for (int i = 0; i < 4; i++) ck_assert_uint_eq(ex_res.bits[i], res.bits[i]);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(float_decimal_4) {
  float num = INFINITY;
  decimal res = {{0}};
  decimal ex_res = {{0}};

  int exepted_result = 1, real_result = from_float_to_decimal(num, &res);

  for (int i = 0; i < 4; i++) ck_assert_uint_eq(ex_res.bits[i], res.bits[i]);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(float_decimal_5) {
  float num = NAN;
  decimal res = {{0}};
  decimal ex_res = {{0}};

  int exepted_result = 1, real_result = from_float_to_decimal(num, &res);

  for (int i = 0; i < 4; i++) ck_assert_uint_eq(ex_res.bits[i], res.bits[i]);

  ck_assert_int_eq(exepted_result, real_result);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  decimal val;
  float a = 1.0F / 0.0F;
  int err_check = from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  decimal val;
  float a = NAN;
  int err_check = from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  decimal val;
  from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

Suite *from_float_to_decimal_suite_create(void) {
  Suite *suite = suite_create("from float to decimal");
  TCase *tcase_core = tcase_create("Core of from float to decimal");

  tcase_add_test(tcase_core, float_decimal_1);
  tcase_add_test(tcase_core, float_decimal_2);
  tcase_add_test(tcase_core, float_decimal_3);
  tcase_add_test(tcase_core, float_decimal_4);
  tcase_add_test(tcase_core, float_decimal_5);
  tcase_add_test(tcase_core, from_float_to_decimal_4);
  tcase_add_test(tcase_core, from_float_to_decimal_6);
  tcase_add_test(tcase_core, from_float_to_decimal_7);

  suite_add_tcase(suite, tcase_core);

  return suite;
}