#include "../decimal.h"

int from_int_to_decimal(int src, decimal *dst) {
  int err = 0;

  if (dst == NULL) {
    err = 1;
  } else {
    clear_decimal(dst);

    if (src < 0) {
      set_sign(dst, 1);
      src = -src;
    }

    if (src > MAX_INT) {
      err = 1;
    } else {
      dst->bits[0] = src;
    }
  }

  return err;
}