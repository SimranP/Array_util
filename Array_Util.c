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
 

void * findFirst(ArrayUtil util, MatchFunc* match, void* hint){
  int * array = (int *)util.base;
  for(int i = 0;i < util.length * util.typeSize;i+=util.typeSize){
     if((*match)(hint,&util.base[i])) return &util.base[i];  
  };
  return NULL;
};

void * findLast(ArrayUtil util, MatchFunc* match, void* hint){
  int * array = (int *)util.base;
  void *result = NULL;
  for(int i = 0;i < util.length * util.typeSize;i+=util.typeSize){
     if((*match)(hint,&util.base[i])) 
      result = &util.base[i];  
  };
  return result;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
  int count = 0;
  for(int i = 0;i < util.length * util.typeSize;i+=util.typeSize){
     if((*match)(hint,&util.base[i])) 
      count++;
  };
  return count;
};

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
  int count = 0;
  for(int i = 0;i < util.length * util.typeSize;i+=util.typeSize){
    if((*match)(hint,&util.base[i])){
      if(count < maxItems){
        ((int *)(*destination))[count] = ((char *)util.base)[i];
        count++;
      }
    }
  };
  return count;
};

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
   for(int i = 0;i < source.length * source.typeSize ;i+= source.typeSize)
        (*convert)(hint,&source.base[i],&destination.base[i]);
};

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue){
  void * reducedValue = initialValue;
   for(int i = 0;i < util.length * util.typeSize ;i+= util.typeSize){
     reducedValue = (*reducer)(hint,reducedValue,&util.base[i]);
   }
   return reducedValue;
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
   for(int i = 0;i < util.length * util.typeSize ;i+= util.typeSize)
     (*operation)(hint,&util.base[i]);
};

