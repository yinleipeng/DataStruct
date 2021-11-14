#include "seqlist.h"

/*
typedef void SeqList;
typedef void SeqListNode;
SeqList* SeqList_Create(int capacity);                        //创建一个空的线性表
int SeqList_Length(SeqList* list);                            //获取线性表的长度
int SeqList_Capacity(SeqList* list);                          //获取线性表的容量
int SeqList_Insert(SeqList* list,SeqListNode* node,int pos);  //将节点插入到某位置
SeqListNode* SeqList_Get(SeqList* list,int pos);              //获取线性表上的节点
void SeqList_Destroy(SeqList* list);                          //销毁线性表
void SeqList_Clear(SeqList* list);                            //清空线性表
SeqListNode* SeqList_Delet(SeqList* list,int pos);           //删除某节点
*/

typedef struct student_
{
   /* data */
   char name[20];
   int age;
}student;


int main(int argc, char **argv) {
   
   /***********************************test the seqlist*********************************/
   student S0,S1,S2,S3;
   S0.age = 10;
   S1.age = 11;
   S2.age = 12;
   S3.age = 13;
   int rte = 0;

   /*create the seqlist*/
   SeqList *SeqListPrt;
   SeqListPrt = SeqList_Create(10);
   if(SeqListPrt == NULL) {
      printf("the SeqListPrt is NULL");
   }

   /*insert the seqlist*/
   rte = SeqList_Insert(SeqListPrt,(SeqListNode*)&S0,0);
   if(rte != 0) {
      printf("the SeqList_Insert err\n");
   }
   rte = SeqList_Insert(SeqListPrt,(SeqListNode*)&S1,0);
   if(rte != 0) {
      printf("the SeqList_Insert err\n");
   }
   rte = SeqList_Insert(SeqListPrt,(SeqListNode*)&S2,0);
   if(rte != 0) {
      printf("the SeqList_Insert err\n");
   }
   rte = SeqList_Insert(SeqListPrt,(SeqListNode*)&S3,0);
   if(rte != 0) {
      printf("the SeqList_Insert err\n");
   }

   /*get the len*/
   int len = SeqList_Length(SeqListPrt);
   printf("the len is %d\n",len);

   /*get the cap*/                       
   int cap =  SeqList_Capacity(SeqListPrt);
   printf("the cap is %d\n",cap);

   /*delet the node*/
   SeqList_Delet(SeqListPrt,0);

   /*get the node*/  
   student *node;
   node = (student*)SeqList_Get(SeqListPrt,0);
   if(node == NULL) {
      printf("the SeqList_Get return is NULL\n");
   }
   printf("the SeqList_Get student age is %d\n",node->age);

   /*delet the seqlist*/
   SeqList_Destroy(SeqListPrt);
   /*clear the seqlist*/                        
   SeqList_Clear(SeqListPrt);
   /***********************************test the seqlist end******************************/

   return 0;
}
