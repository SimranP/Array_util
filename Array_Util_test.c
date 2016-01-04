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
  printf("test passed\n\n");
};

void test2_for_create_array(){
  Array numbers = create(4,2); 
  assert(((int *)numbers.base)[0]==0);
  assert(((int *)numbers.base)[1]==0);
  printf("test passed\n\n");
};

void test_for_resize_array(){
  Array numbers = create(4,5);
  printf("Collected :typesize = %d , length = %d , base = %p\n",numbers.typeSize,numbers.length,numbers.base);
  Array new_numbers = resize(numbers,6);
  printf("Expected :typesize = %d , length = %d , base = %p\n",4,6,numbers.base);
  assert(new_numbers.base == numbers.base);
  assert(new_numbers.length == 6);
  assert(numbers.typeSize == 4);
  printf("test passed\n\n");
};
  
void test2_for_resize_array(){
  Array numbers = create(4,5);
  printf("Collected :typesize = %d , length = %d , base = %p\n",numbers.typeSize,numbers.length,numbers.base);
  Array new_numbers = resize(numbers,3);
  printf("Expected :typesize = %d , length = %d , base = %p\n",4,3,numbers.base);
  assert(new_numbers.base == numbers.base);
  assert(new_numbers.length == 3);
  assert(numbers.typeSize == 4);
  printf("test passed\n\n");
};

void test_for_areEqual(){
  Array a = create(6,5);
  Array b = create(6,5);
  assert(areEqual(a,b)==1);
  printf("test passed\n\n");
};

void test2_for_areEqual(){
  Array a = create(7,8);
  Array b = create(8,9);
  Array c = create(8,7);
  Array d = create(8,9);
  assert(areEqual(a,b)==0);
  assert(areEqual(c,b)==0);
  printf("test passed\n\n");
};

int main(void){
  printf("1.test_for_create_array: 'create' creates an array and adds three fields to it\n");
  test_for_create_array();
  printf("2.test2_for_create_array : 'create' initialize everything to 0\n");
  test2_for_create_array();
  printf("3.test_for_resize_array:'resize' increases the size of array for greater given length\n");
  test_for_resize_array();
  printf("4.test2_for_resize_array:'resize' decreases the size of array for lesser given length\n");
  test2_for_resize_array();
  printf("5.test_for_areEqual:'forEqual' gives 1 when given two arrays are same\n");
  test_for_areEqual();
  printf("6.test_for_areEqual:'forEqual' gives 0 when given two arrays are different\n");
  test2_for_areEqual();
  return 0;
};

