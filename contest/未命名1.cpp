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
	ElemType   data; // ������        
	struct LNode *next; // ָ����  
}LNode, *LinkList;  
Status InitList_L(LinkList &L) 
 {    
  	L=(LinkList) malloc (sizeof(LNode)); 
 	if(L==NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        return 0;
    }
    L->next=NULL;
    return OK;  
}  
Status Create(LinkList &L,int n)
{
    LinkList P,Q;
    P=L;
    printf("�밴����˳������Ԫ�أ�\n");
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
	    
   //������б�mink���Ԫ��
   	Q=P->next;
	while(P && Q->data<maxk) 
	{  
		//Print(L);cout<<P->data<<'#'<<endl;
		
		P->next=Q->next;
		free(Q);
		Q=P->next;
 		
   		
 	} //Q�ǵ�һ����С��maxk��Ԫ�� 
 
}

int main()
{
    LinkList L;
    int Number,min,max;
    InitList_L(L); 
    printf("������Ԫ�ظ�����\n");
    scanf("%d",&Number);
    Create(L,Number); 
	Print(L);
    printf("������minkԪ�غ�maxkԪ�أ�\n");
    scanf("%d %d",&min,&max);
	Delete_Between(L,min,max); 
    printf("ȥ������mink��С��maxkԪ�غ�����\n");
    Print(L);
    return 0;
}
