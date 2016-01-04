#include <stdio.h>
#include <assert.h>
#include "Array_Util.h"

void test_for_create_array(){
  printf("Expected :typesize = %d , length = %d , base = %s\n",4,5,"some address");
  Array numbers = create(4,5);
  assert(numbers.base);
  assert(numbers.length == 5);
  assert(numbers.typeSize == 4);
  printf("Collected :typesize = %d , length = %d , base = %p\n",numbers.typeSize,numbers.length,numbers.base);
  printf("test passed\n");
};

void test_for_resize_array(){
  Array numbers = create(4,5);
  printf("Collected :typesize = %d , length = %d , base = %p\n",numbers.typeSize,numbers.length,numbers.base);
  Array new_numbers = resize(numbers,6);
  printf("Expected :typesize = %d , length = %d , base = %p\n",4,5,numbers.base);
  assert(new_numbers.base == numbers.base);
  assert(new_numbers.length == 6);
  assert(numbers.typeSize == 4);
  printf("test passed\n");
};

int main(void){
  test_for_create_array();
  test_for_resize_array();
  return 0;
};

