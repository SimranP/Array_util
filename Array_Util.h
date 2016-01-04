typedef struct array {
  void *base;
  int typeSize;
  int length;
} Array;

Array create(int typeSize, int length);
Array resize(Array util, int length);
int areEqual(Array a , Array b);
int findIndex(Array a,void* element); 
