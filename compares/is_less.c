#include "compares.h"

int is_less(decimal num1, decimal num2) {
  return sample_compare(num1, num2, IS_LESS_PARAMETR);
}