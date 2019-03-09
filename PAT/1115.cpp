#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<malloc.h>
#include<algorithm>
using namespace std;
struct Node{
	int v;
	Node *left,*right;
};
int cnt[1005],l1,l2;
void add(int deep,Node* &root,int v){
	if(deep > l1){
		l2 = l1;
		l1 = deep;
	}
	if(root==NULL){
		root = (Node*)malloc(sizeof(Node));
		root->left = root->right = NULL;
		root->v = v;
		cnt[deep]++;
		return;
	}
	if(v <= root->v) add(deep+1,root->left,v);
	else add(deep+1,root->right,v);
}
int main()
{
	int N;
	scanf("%d",&N);
	int a;
	Node *root =  NULL;
	memset(cnt,0,sizeof(cnt));
	l1 = 1;
	l2 = 0;
	for(int i = 0;i < N;i++){
		scanf("%d",&a);
		add(1,root,a);
	}
	printf("%d + %d = %d\n",cnt[l1],cnt[l2],cnt[l1]+cnt[l2]);
	return 0;
}
