#include "others.h"

int truncate(decimal value, decimal *result) {
  decimal exp_tens = exp_ten(get_scale(value));

  int max_scale = 28;
  int code = 0;

  if (!result || (get_scale(value) > max_scale))
    code = 1;
  else {
    code = div_and_round(IS_TRUNCATE, value, exp_tens, result);

    if (code != 0) code = 1;
  }

  return code;
}