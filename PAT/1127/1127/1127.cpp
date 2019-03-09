#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	int val,f;
	node *right,*left;
};
int postorder[35],inorder[35];
void build(node* &now,int root,int l,int r,int lastf)
{
	if(l>r) return;
	if(now==NULL)
	{
		now=new node();
		now->val=postorder[root];
		now->f=lastf+1; 
	}
	int i;
	for(i=0;i<=r;i++)
	{
		if(inorder[i]==postorder[root]) break;
	}
	build(now->left,root-(r-i+1),l,i-1,now->f);
	build(now->right,root-1,i+1,r,now->f);
}
vector<int> ans[35];
void bfs(node *root)
{
	queue<node*> q;  
	q.push(root);
	while(!q.empty())
	{
		node *now=q.front();
		q.pop();
		ans[now->f].push_back(now->val);
		if(now->left !=NULL) q.push(now->left);
		if(now->right !=NULL) q.push(now->right);
	}
}
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++) scanf("%d",&inorder[i]);
	for(int i=0;i<N;i++) scanf("%d",&postorder[i]);
	node *tree=NULL;
	build(tree,N-1,0,N-1,0);
	bfs(tree);
	printf("%d",tree->val);
	for(int i=2;i<35;i++)
	{
		if(!ans[i].empty())
		{
			if(i&1) for(int j=ans[i].size()-1;j>=0;j--) printf(" %d",ans[i][j]);
			else for(int j=0;j<ans[i].size();j++) printf(" %d",ans[i][j]);
		}
	}
	printf("\n");
	return 0;
}