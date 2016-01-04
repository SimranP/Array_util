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

int areEqual(Array a, Array b){
  if(!(a.typeSize == b.typeSize) || !(a.length == b.length))
    return 0;
  int i = 0;
  while(i<a.length){
    if(!(((int *)a.base)[i]==((int *)b.base)[i])){
      return 0;
    }
    i++;
  }
  return 1;
};

int findIndex(Array a,void* element){
 for(int i = 0;i < a.length; i++){
    if(((int *)a.base)[i] == element){
     return i;
    }
 };
return -1;
};

