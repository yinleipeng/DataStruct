#include "seqlist.h"

typedef struct{
   int capacity;         //容量
   int length;           //长度
   unsigned int *node;   //节点指针
}TSeqList;

/*创建一个空的线性表*/
SeqList* SeqList_Create(int capacity) {

   int ret = 0;
   TSeqList *tmp = NULL;

   tmp = (TSeqList*)malloc(sizeof(TSeqList));
   if(tmp == NULL) {
     ret = -1;
     printf("func SeqList_Create() err:%d\n",ret);
     return NULL;
   }
   memset(tmp,0,sizeof(TSeqList));

  tmp->node =(unsigned int*)malloc(sizeof(unsigned int*)*capacity);
  if(tmp->node == NULL) {
     ret = -2;
     printf("func SeqList_Create() err:%d\n",ret);
     return NULL;
   }

  tmp->length = 0;
  tmp->capacity = capacity;
  return tmp;
}

/*销毁线性表*/
void SeqList_Destroy(SeqList* list) {

  TSeqList *tlist = NULL;
  int ret = 0;

  if(list == NULL) {
     ret = -1;
     printf("funcSeqList_Destroy() err:%d ",ret);
     return ;
  }

  tlist=(TSeqList*)list;
  if(tlist->node != NULL) {
    free(tlist->node);
  }
  free(tlist);

  return;
}

/*清空线性表*/
void SeqList_Clear(SeqList* list) {

   int ret =0 ;
   TSeqList *tlist=NULL;

   if(list == NULL) {
     ret = -1;
     printf("func SeqList_Clear() err:%d\n",ret);
     return;
   }

   tlist = (TSeqList*)list;
   tlist->length = 0;
   return ;
}

/*获取线性表的长度*/
int SeqList_Length(SeqList* list) {

   int ret =0 ;
   TSeqList *tlist = NULL;

   if(list == NULL) {
     ret = -1;
     printf("func SeqList_Clear() err:%d\n",ret);
     return ret;
   }

  tlist =(TSeqList*) list;
  return tlist->length;
}

/*获取线性表的容量*/
int SeqList_Capacity(SeqList* list) {

   int ret = 0;
   TSeqList *tlist = NULL;

   if(list == NULL) {
     ret = -1;
     printf("func SeqList_Clear() err:%d\n",ret);
     return ret;
   }

  tlist = (TSeqList*)list;
  return tlist->capacity;
}

/*将节点插入到某位置*/
int SeqList_Insert(SeqList* list,SeqListNode* node,int pos) {

   int i = 0;
   int ret = 0;
   TSeqList *tlist = NULL;

   if(list == NULL || node == NULL || pos < 0) {
     ret = -1;
     printf("func SeqList_Clear() err:%d\n",ret);
     return ret;
   }

  tlist = (TSeqList*) list;
  if(tlist->length >= tlist->capacity){
      ret = -2;
      printf("func SeqList_Insert() err:%d\n",ret);
      return ret;
  }

  if(tlist->length <= pos) {
    pos = tlist->length;
  }
  for(i = tlist->length; i > pos; i--) {
     tlist->node[i] = tlist->node[i-1];
  }
  tlist->node[i]=(unsigned int*)node;
  tlist->length++;
  return ret;
}

/*获取节点位置*/
SeqListNode *seqlist_get(SeqList* List,int pos) {

  SeqListNode *ret = 0;
  TSeqList *tlist = NULL;

  if(List == NULL || pos < 0) {
    ret = -1;
    printf("func seqlist_get() err: %d\n ",ret);
    return NULL;
  }

  tlist = (TSeqList*)List;
  ret = (SeqListNode*)tlist->node[pos];
  return ret;
}

/*删除线性表指定位置上的节点*/
SeqListNode *SeqList_Delet(SeqList* List,int pos) {

  int i = 0;
  SeqListNode *ret = 0;
  SeqListNode *node = 0;
  TSeqList *tlist;

  if(List == NULL || pos < 0) {
    ret = -1;
    printf("func SeqList_Delet() err:%d",ret);
    return ret;
  }

  tlist = (TSeqList*)List;
  node = tlist->node[pos];
  for(i = pos + 1;i < tlist->length; i++) {
     tlist->node[i-1] = tlist->node[i];
  }
  tlist->length -= 1;
  return ret;
}
