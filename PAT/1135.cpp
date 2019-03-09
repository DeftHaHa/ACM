#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
#include<cmath>
using namespace std;
struct Node{
	int v;
	Node *left,*right;
}*root;
void addNode(Node* &now,int v){
	if(now == NULL){
		now = (Node *)malloc(sizeof(Node));
		now->left = now->right = NULL;
		now->v = v;
		return;
	}
	if(abs(now->v) >= abs(v)) addNode(now->left,v);
	else addNode(now->right,v);
}
bool ok,flag;
int cnt;
void dfs(Node * now,int tot){
	if(now ==  NULL){
		if(!flag){
			flag = true;
			cnt = tot;
		}
		else if(cnt != tot) ok = false;
		return;
	}
	tot += (now->v > 0);
	if(now->v < 0 && now->left && now->left->v < 0) ok = false;
	  if(now->v < 0 && now->right && now->right->v < 0) ok = false;
	dfs(now->left,tot);
	dfs(now->right,tot);
}
int main(){
	int T;
	scanf("%d",&T);
	int N,v;
	while(T--){
		scanf("%d",&N);
		root = NULL;
		for(int i = 1;i <= N;i++){
			scanf("%d",&v);
			addNode(root,v);
		}
		ok = true;
		flag = false;
		if(root && root->v < 0) ok = false;
		dfs(root,0);
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
