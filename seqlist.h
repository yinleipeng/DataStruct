
#ifndef _SEQLIST_H_ 
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void SeqList;
typedef void SeqListNode;

extern SeqList* SeqList_Create(int capacity);                        //创建一个空的线性表
extern void SeqList_Destroy(SeqList* list);                          //销毁线性表
extern void SeqList_Clear(SeqList* list);                            //清空线性表
extern int SeqList_Length(SeqList* list);                            //获取线性表的长度
extern int SeqList_Capacity(SeqList* list);                          //获取线性表的容量
extern int SeqList_Insert(SeqList* list,SeqListNode* node,int pos);  //将节点插入到某位置
extern SeqListNode* SeqList_Get(SeqList* list,int pos);              //获取线性表上的节点
extern SeqListNode* SeqList_Delet(SeqList* list,int pos);           //删除某节点

#endif
