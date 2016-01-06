typedef struct arrayUtil{
  void *base;
  int typeSize;
  int length;
} ArrayUtil;
typedef int (* MatchFunc)(void *hint,void *item);

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int areEqual(ArrayUtil a , ArrayUtil b);
int findIndex(ArrayUtil a,void* element);
void dispose(ArrayUtil a);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
