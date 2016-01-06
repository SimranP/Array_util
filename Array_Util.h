typedef struct arrayUtil{
  void *base;
  int typeSize;
  int length;
} ArrayUtil;
typedef int (* MatchFunc)(void *hint,void *item);
typedef void (*ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);
typedef void* (*ReducerFunc)(void* hint, void* previousItem, void* item);
typedef void (*OperationFunc)(void* hint, void* item);


ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int areEqual(ArrayUtil a , ArrayUtil b);
int findIndex(ArrayUtil a,void* element);
void dispose(ArrayUtil a);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
