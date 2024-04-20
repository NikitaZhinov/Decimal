#include "../decimal.h"

int from_float_to_decimal(float src, decimal *dst) {
  int err = OK;

  if (dst) {
    clear_decimal(dst);

    if (!(fabs(src) < NEAR_ZERO && fabsf(src) > 0) &&
        !(fabsf(src) >= MAX_DECIMAL) && !isinf(src) && !isnan(src)) {
      int sign = 0;
      long int temp = (long int)src;
      long int scale = 0;

      if (src < 0) {
        sign = 1;
        src = -(src);
      }

      while (src - ((float)temp / (long int)(pow(10, scale))) != 0) {
        scale++;
        temp = src * (long int)(pow(10, scale));
      }

      from_int_to_decimal(temp, dst);

      if (sign) {
        set_sign(dst, 1);
      }

      set_scale(dst, scale);

    } else {
      err = ERROR;
    }

  } else {
    err = ERROR;
  }

  return err;
}