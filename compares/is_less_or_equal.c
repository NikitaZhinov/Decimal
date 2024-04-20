#include "compares.h"

int is_less_or_equal(decimal num1, decimal num2) {
  return sample_compare(num1, num2, IS_LESS_OR_EQUAL_PARAMETR);
}