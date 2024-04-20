#include "converting.h"

void clear_decimal(s21_decimal* decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}