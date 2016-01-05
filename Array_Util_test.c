#include <stdio.h>
#include <assert.h>
#include "Array_Util.h"

int isEven(void* hint,void* item);
void test_for_create_array(){
  printf("Expected :typesize = %d , length = %d , base = %s\n",4,5,"some address");
  ArrayUtil numbers = create(4,5);
  assert(numbers.base);
  assert(numbers.length == 5);
  assert(numbers.typeSize == 4);
  printf("Collected :typesize = %d , length = %d , base = %p\n",numbers.typeSize,numbers.length,numbers.base);
  printf("test passed\n\n");
};

void test2_for_create_array(){
  ArrayUtil numbers = create(4,2); 
  assert(((int *)numbers.base)[0]==0);
  assert(((int *)numbers.base)[1]==0);
  printf("test passed\n\n");
};

void test3_for_create_array(){
  ArrayUtil a = create(2,6);
  ((char *)a.base)[0] = 'a';
  ((char *)a.base)[1] = 'p';
  ((char *)a.base)[2] = 'p';
  ((char *)a.base)[3] = 'l';
  ((char *)a.base)[4] = 'e';
  ((char *)a.base)[5] = 0;
  ((char *)a.base)[1] = 'c';
  printf("%s\n",((char *)a.base));
};
  
void test_for_resize_array(){
  ArrayUtil numbers = create(4,5);
  printf("Collected :typesize = %d , length = %d , base = %p\n",numbers.typeSize,numbers.length,numbers.base);
  ArrayUtil new_numbers = resize(numbers,6);
  printf("Expected :typesize = %d , length = %d , base = %p\n",4,6,numbers.base);
  assert(new_numbers.base == numbers.base);
  assert(new_numbers.length == 6);
  assert(numbers.typeSize == 4);
  printf("test passed\n\n");
};
  
void test2_for_resize_array(){
  ArrayUtil numbers = create(4,5);
  ((int *)numbers.base)[4] = 8;
  ((int *)numbers.base)[3] = 8;
  ((int *)numbers.base)[2] = 9;
  ((int *)numbers.base)[1] = 8;
  ((int *)numbers.base)[0] = 6;
  printf("Collected :typesize = %d , length = %d , base = %p\n",numbers.typeSize,numbers.length,numbers.base);
  ArrayUtil new_numbers = resize(numbers,3);
  printf("Expected :typesize = %d , length = %d , base = %p\n",4,3,numbers.base);
  assert(new_numbers.base == numbers.base);
  assert(new_numbers.length == 3);
  assert(numbers.typeSize == 4);
  printf("test passed\n\n");
};

void test3_for_resize_array(){
  ArrayUtil numbers = create(4,5);
  ((int *)numbers.base)[4] = 8;
  ((int *)numbers.base)[3] = 8;
  ((int *)numbers.base)[2] = 9;
  ((int *)numbers.base)[1] = 8;
  ((int *)numbers.base)[0] = 6;
  ArrayUtil new_numbers = resize(numbers,8);
  assert(((int *)new_numbers.base)[0] == ((int *)numbers.base)[0]);
  assert(((int *)new_numbers.base)[1] == ((int *)numbers.base)[1]);
  assert(((int *)new_numbers.base)[2] == ((int *)numbers.base)[2]);
  assert(((int *)new_numbers.base)[3] == ((int *)numbers.base)[3]);
  assert(((int *)new_numbers.base)[4] == ((int *)numbers.base)[4]);
  assert(((int *)new_numbers.base)[5] == ((int *)numbers.base)[5]);
  assert(((int *)new_numbers.base)[6] == 0);
  assert(((int *)new_numbers.base)[7] == 0);
  printf("test passed\n\n");
};

void test_for_areEqual(){
  ArrayUtil a = create(6,5);
  ArrayUtil b = create(6,5);
  assert(areEqual(a,b)==1);
  printf("test passed\n\n");
};

void test2_for_areEqual(){
  ArrayUtil a = create(7,8);
  ArrayUtil b = create(8,9);
  ArrayUtil c = create(8,7);
  ArrayUtil d = create(8,9);
  assert(areEqual(a,b)==0);
  assert(areEqual(c,b)==0);
  printf("test passed\n\n");
};

void test3_for_areEqual(){
  ArrayUtil a = create(4,3);
  ArrayUtil b = create(4,3);
  ((int *)a.base)[0] = 8;
  ((int *)b.base)[0] = 8;
  assert(areEqual(a,b)==1);
  printf("test passed\n\n");
};

void test4_for_areEqual(){
  ArrayUtil a = create(4,3);
  ArrayUtil b = create(4,3);
  ((int *)a.base)[0] = 8;
  ((int *)b.base)[0] = 9;
  assert(areEqual(a,b)==0);
  printf("test passed\n\n");
};

void test_for_findIndex(){
  ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 8;
  assert(findIndex(a,(int *)8)==4);
  printf("test passed\n\n");
};

void test2_for_findIndex(){
  ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 8;
  assert(findIndex(a,(int *)4)==-1);
  printf("test passed\n\n");
};

void test_for_dispose(){
  ArrayUtil a = create(5,6);
  ((int *)a.base)[4] = 8;
  ((int *)a.base)[3] = 8;
  ((int *)a.base)[2] = 9;
  ((int *)a.base)[1] = 8;
  ((int *)a.base)[5] = 8;
  ((int *)a.base)[0] = 6;
  dispose(a);
  //printf("%d\n",a.length);
  //assert(a.length == 0);
  printf("test passed\n");
};

int isEven(void* hint,void* item){
    int n = *(int *)item;
    return !(n%2);
};

void test_for_findFirst(){
  ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 3;
  ((int *)a.base)[3] = 4;
  ((int *)a.base)[2] = 9;
  ((int *)a.base)[1] = 7;
  ((int *)a.base)[5] = 8;
  ((int *)a.base)[0] = 9;
  int divisor = 7;
  void * hint = &divisor;
  assert(4==*(int *)findFirst(a,isEven,hint));
  printf("test passed\n\n");
};

int isDivisible(void *hint,void *item){
  int n = *(int *)item;
  int d = *(int *)hint;
  return !(n%d);
};

void test2_for_findFirst(){
 ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 3;
  ((int *)a.base)[3] = 4;
  ((int *)a.base)[2] = 9;
  ((int *)a.base)[1] = 8;
  ((int *)a.base)[5] = 7;
  ((int *)a.base)[0] = 9;
  int divisor = 7;
  void * hint = &divisor;
  assert(7==*(int *)findFirst(a,isDivisible,hint));
  printf("test passed\n\n");
};

void test3_for_findFirst(){
 ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 3;
  ((int *)a.base)[3] = 4;
  ((int *)a.base)[2] = 9;
  ((int *)a.base)[1] = 8;
  ((int *)a.base)[5] = 7;
  ((int *)a.base)[0] = 9;
  int divisor =17;
  void * hint = &divisor;
  assert(NULL==(int *)findFirst(a,isDivisible,hint));
  printf("test passed\n\n");
};
void test_for_findLast(){
 ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 3;
  ((int *)a.base)[3] = 4;
  ((int *)a.base)[2] = 7;
  ((int *)a.base)[1] = 8;
  ((int *)a.base)[5] = 14;
  ((int *)a.base)[0] = 9;
  int divisor = 7;
  void * hint = &divisor;
  assert(14==*(int *)findLast(a,isDivisible,hint));
  printf("test passed\n\n");
};

void test2_for_findLast(){
 ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 3;
  ((int *)a.base)[3] = 4;
  ((int *)a.base)[2] = 10;
  ((int *)a.base)[1] = 8;
  ((int *)a.base)[5] = 11;
  ((int *)a.base)[0] = 9;
  int divisor = 17;
  void * hint = &divisor;
  assert(NULL == (int *)findLast(a,isDivisible,hint));
  printf("test passed\n\n");
};

void test_for_count(){
 ArrayUtil a = create(4,6);
  ((int *)a.base)[4] = 3;
  ((int *)a.base)[3] = 4;
  ((int *)a.base)[2] = 10;
  ((int *)a.base)[1] = 8;
  ((int *)a.base)[5] = 11;
  ((int *)a.base)[0] = 9;
  int divisor = 3;
  void * hint = &divisor;
  assert(2 == count(a,isDivisible,hint));
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
  printf("4.test3_for_resize_array:'resize' doesn't effect the values form the array\n");
  test3_for_resize_array();
  printf("5.test_for_areEqual:'areEqual' gives 1 when given two arrays are same\n");
  test_for_areEqual();
  printf("6.test2_for_areEqual:'areEqual' gives 0 when given two arrays are different\n");
  test2_for_areEqual();
  printf("7.test3_for_areEqual:'areEqual' gives 1 when given two arrays have same values\n");
  test3_for_areEqual();
  printf("8.test4_for_areEqual:'areEqual' gives 0 when given two arrays have same values\n");
  test4_for_areEqual();
  printf("9.test_for_findIndex:'findIndex' gives index number  when it has the given element\n");
  test_for_findIndex();
  printf("10.test2_for_findIndex:'findIndex' gives index number  when it doesn't have the given element\n");
  test2_for_findIndex();
  printf("11.test2_for_dispose:'dispose' releases the memory allocated in array's base field\n");
  test_for_dispose();
  test3_for_create_array();
  printf("12.test_for_findFirst:'findFirst' gives the pointer to the firstly matched value if matched value is found\n");
  test_for_findFirst();
  printf("13.test2_for_findFirst:'findFirst' gives the pointer to the firstly matched value if matched value is found\n");
  test2_for_findFirst();
  printf("14.test3_for_findFirst:'findFirst' gives the NULL if no value matched the condition\n");
  test3_for_findFirst();
  printf("15.test_for_findLast:'findLast' gives the pointer to the lastly matched value if matched value is found\n");
  test_for_findLast();
  printf("16.test_for_findLast:'findLast' gives the NUll if no value matched the condition\n");
  test2_for_findLast();
  printf("17.test_for_count:'count' gives count of values that matched the condition\n");
  test_for_count();
  return 0;
};

