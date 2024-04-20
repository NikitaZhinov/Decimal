#include "compares.h"

int is_greater_or_equal(decimal num1, decimal num2) {
  return sample_compare(num1, num2, IS_GREATER_OR_EQUAL_PARAMETR);
}