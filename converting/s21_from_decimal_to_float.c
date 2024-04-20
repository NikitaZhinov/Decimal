#include "../s21_decimal.h"
/**
 * @brief This function converting number from s21_decimal to float value
 *
 * In loop:
 * Every bit of decimal convert to double, every bit multiple as 2 powered by
 * number of bit position
 *
 * @param src s21_decimal binary value
 * @param dst result float value as pointer
 * @return ERROR int value
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err = OK;

  if (dst == NULL) {
    err = ERROR;
  } else {
    *dst = 0.0f;
    double tmp = 0.0;

    int sign = get_sign(src);
    int scale = get_scale(src);

    for (int i = 0; i < 96; i++) {
      if (get_bit(src, i)) {
        tmp += pow(2.0, i);
      }
    }

    double tenscale = pow(10, scale);
    tmp /= tenscale;

    if (sign == 1) {
      tmp *= -1.0;
    }

    *dst = (float)tmp;
  }

  return err;
}