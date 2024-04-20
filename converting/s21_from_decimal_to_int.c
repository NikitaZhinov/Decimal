#include "../s21_decimal.h"

/**
 * @brief
 *
 * 0x80000000 == -INT_MAX == 01000000000000000000000000000000
 *
 *
 * @param src input s21_decimal value
 * @param dst output int value as pointer
 * @return int
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int err = OK;
  s21_decimal int_min = {{0x80000000, 0x0, 0x0, 0x80000000}};
  s21_decimal int_max = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  if (dst == NULL) {
    err = ERROR;
  } else {
    *dst = 0;
    int scale = get_scale(src);

    if ((s21_is_less(src, int_min) || s21_is_greater(src, int_max)) == 1) {
      err = ERROR;
    } else {
      *dst = (int)src.bits[0];

      if (get_sign(src) == 1 && *dst != -2147483648) {
        *dst = -*dst;
      }

      if (scale != 0) {
        int tenscale = pow(10, scale);
        *dst /= tenscale;
      }
    }
  }

  return err;
}