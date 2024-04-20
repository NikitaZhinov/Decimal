#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int err = 0;

  if (dst == NULL) {
    err = 1;
  } else {
    clear_decimal(dst);

    if (src < 0) {
      set_sign(dst, 1);
      src = -src;
    }

    if (src > S21_MAX_INT) {
      err = 1;
    } else {
      dst->bits[0] = src;
    }
  }

  return err;
}