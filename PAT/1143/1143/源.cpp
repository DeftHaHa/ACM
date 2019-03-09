#include<iostream>
#include<cstring>
#include<cstdio>
#include<malloc.h>
#include<unordered_set>
using namespace std;
struct Node
{
	int val;
	Node *right,*left;
};
int N,M;
int pos=1;
int a[200005];
void build(Node *root,int l,int r)
{
	if(l>r) return;
	int tag=-1;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>=root->val)
		{
			tag=i;
			break;
		}
	}
	if(tag>l||tag==-1)
	{
		Node *x = (Node*)malloc(sizeof(Node));
		x->left = x->right =NULL;
		x->val=a[l];
		root->left = x;
		build(x,l+1,tag-1);
	}
	if(tag!=-1)
	{
		Node *x = (Node*)malloc(sizeof(Node));
		x->left = x->right =NULL;
		x->val=a[tag];
		root->right = x;
		build(x,tag+1,r);
	}
}
int u,v;
bool flag;
void dfs(Node *now)
{
	if(!now) return;
	if(now->val == u)
	{
		printf("%d is an ancestor of %d.\n",u,v);
		return;
	}
	else if(now->val == v)
	{
		printf("%d is an ancestor of %d.\n",v,u);
		return;
	}
	else if(now->val > u&& now->val < v)
	{
		if(flag) printf("LCA of %d and %d is %d.\n",v,u,now->val);
		else printf("LCA of %d and %d is %d.\n",u,v,now->val);
		return;
	}
	else 
	{
		if(now->val < u) dfs(now->right);
		else dfs(now->left);
	}
	
}
int main()
{
	cin>>M>>N;
	unordered_set<int> S;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		S.insert(a[i]);
	}
	Node *root = (Node*)malloc(sizeof(Node));
	root->val=a[0];
	root->right = root->left = NULL;
	build(root,1,N-1);
	while(M--)
	{
		
		scanf("%d%d",&u,&v);
		int flag1=S.count(u),flag2=S.count(v);
		if(flag1&&flag2)
		{
			if(u>v)
			{
				swap(u,v);
				flag=true;
			}
			else flag=false;
			dfs(root);
		}
		else if(!flag1&&!flag2) printf("ERROR: %d and %d are not found.\n",u,v);
		else if(!flag1) printf("ERROR: %d is not found.\n",u);
		else printf("ERROR: %d is not found.\n",v);
	}
	system("pause");
	return 0;
}