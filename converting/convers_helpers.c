#include "converting.h"

void clear_decimal(decimal* decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}