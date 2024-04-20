#include "others.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int code = 0;
  *result = value;

  if (!result) code = 1;

  set_sign(result, !(get_sign(*result)));

  return code;
}