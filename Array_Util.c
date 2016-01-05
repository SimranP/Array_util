#include "Array_Util.h"
#include <stdlib.h>

ArrayUtil create(int typeSize, int length){
  ArrayUtil newArrayUtil;
  newArrayUtil.base = calloc(length,typeSize);
  newArrayUtil.typeSize = typeSize;
  newArrayUtil.length = length;
  return newArrayUtil;
};

ArrayUtil resize(ArrayUtil a,int length){
  ArrayUtil array = a;
  realloc(a.base,(length*a.typeSize));
  a.length = length;
  for(int i = 0; i < length; i++){
    ((int *)a.base)[i] = ((int *)array.base)[i];
  };
  return a;
};

int areEqual(ArrayUtil a, ArrayUtil b){
  if(!(a.typeSize == b.typeSize) || !(a.length == b.length))
    return 0;
  int i = 0;
  while(i<a.length){
    if(!(((int *)a.base)[i]==((int *)b.base)[i]))
      return 0;
    i++;
  }
  return 1;
};

int findIndex(ArrayUtil a,void* element){
 for(int i = 0;i < a.length; i++){
    if(((int *)a.base)[i] == element)
     return i;
 };
return -1;
};

void dispose(ArrayUtil a){
  free(a.base);
};
 

void * findFirst(ArrayUtil util, MatchFunc match, void* hint){
  int * array = (int *)util.base;
  for(int i = 0; i<util.length;i++){
     if(match(hint,&array[i])) return &array[i];  
  };
  return NULL;
};

void * findLast(ArrayUtil util, MatchFunc match, void* hint){
  int * array = (int *)util.base;
  void *result = NULL;
  for(int i = 0; i < util.length;i++){
     if(match(hint,&array[i])) 
      result = &array[i];  
  };
  return result;
};

int count(ArrayUtil util, MatchFunc match, void* hint){
  int * array = (int *)util.base;
  int count = 0;
  for(int i = 0; i < util.length;i++){
     if(match(hint,&array[i])) 
      count++;
  };
  return count;
};

