#include "compares.h"

int is_not_equal(decimal num1, decimal num2) {
  return sample_compare(num1, num2, IS_NOT_EQUAL_PARAMETR);
}