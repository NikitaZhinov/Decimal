#include "../decimal.h"
/**
 * @brief This function converting number from decimal to float value
 *
 * In loop:
 * Every bit of decimal convert to double, every bit multiple as 2 powered by
 * number of bit position
 *
 * @param src decimal binary value
 * @param dst result float value as pointer
 * @return ERROR int value
 */
int from_decimal_to_float(decimal src, float *dst) {
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