#include "Array_Util.h"
#include <stdlib.h>

Array create(int typeSize, int length){
  Array newArray;
  newArray.base = calloc(length,typeSize);
  newArray.typeSize = typeSize;
  newArray.length = length;
  return newArray;
};

Array resize(Array a,int length){
  realloc(a.base,(length*a.typeSize));
  a.length = length;
  return a;
};
