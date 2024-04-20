#include "others.h"

int negate(decimal value, decimal *result) {
  int code = 0;
  *result = value;

  if (!result) code = 1;

  set_sign(result, !(get_sign(*result)));

  return code;
}