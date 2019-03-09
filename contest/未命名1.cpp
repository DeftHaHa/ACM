#include <iostream>
#include <stdio.h>      
#include <stdlib.h>           
typedef int ElemType;     
typedef int Status;
using namespace std;      
#define OK 1      
#define ERROR 0      
#define OVERFLOW 1      
#define null 0      
typedef struct LNode
{          
	ElemType   data; // 数据域        
	struct LNode *next; // 指针域  
}LNode, *LinkList;  
Status InitList_L(LinkList &L) 
 {    
  	L=(LinkList) malloc (sizeof(LNode)); 
 	if(L==NULL)
    {
        printf("内存分配失败！\n");
        return 0;
    }
    L->next=NULL;
    return OK;  
}  
Status Create(LinkList &L,int n)
{
    LinkList P,Q;
    P=L;
    printf("请按递增顺序输入元素：\n");
    for(int i=0;i<n;i++)
    {
        Q=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&Q->data);
        P->next=Q;
        P=P->next;
    }
    P->next=NULL;
    return OK;
}
void Print(LinkList & L)
{
    LinkList P;
    P=L->next;
    while(P)
    {
        printf("%d ",P->data);
        P=P->next;
    }
    printf("\n");
}
Status Delete_Between(LinkList& L,int mink,int maxk)
 { 
 	LinkList P,Q;
 	P=L->next;
 	while(P->next) 
 	{         		    
	 	if(P->next->data > mink) break;
		P=P->next; 
	}
	    
   //如果还有比mink大的元素
   	Q=P->next;
	while(P && Q->data<maxk) 
	{  
		//Print(L);cout<<P->data<<'#'<<endl;
		
		P->next=Q->next;
		free(Q);
		Q=P->next;
 		
   		
 	} //Q是第一个不小于maxk的元素 
 
}

int main()
{
    LinkList L;
    int Number,min,max;
    InitList_L(L); 
    printf("请输入元素个数：\n");
    scanf("%d",&Number);
    Create(L,Number); 
	Print(L);
    printf("请输入mink元素和maxk元素：\n");
    scanf("%d %d",&min,&max);
	Delete_Between(L,min,max); 
    printf("去掉大于mink且小于maxk元素后链表：\n");
    Print(L);
    return 0;
}
