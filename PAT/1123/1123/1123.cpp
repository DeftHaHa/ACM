#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int val;
	struct node *left,*right;
};
node* Rrotate(node *tree)
{
	struct node *temp=tree->left;
	tree->left=temp->right;
	temp->right=tree;
	return temp;
}
node* Lrotate(node *tree)
{
	struct node *temp=tree->right;
	tree->right=temp->left;
	temp->left=tree;
	return temp;
}
node* RLrotate(node *tree)
{
	tree->right=Rrotate(tree->right);
	return Lrotate(tree);
}
node* LRrotate(node *tree)
{
	tree->left=Lrotate(tree->left);
	return Rrotate(tree);
}
int getheight(node *tree)
{
	if(tree==NULL) return 0;
	return max(getheight(tree->left),getheight(tree->right))+1;
}
node* insert(node *tree,int val)
{
	if(tree==NULL)
	{
		tree=new node();
		tree->val=val;
		tree->left=tree->right=NULL;
	}
	else if(val < tree->val)
	{
		tree->left=insert(tree->left,val);
		int l=getheight(tree->left);
		int r=getheight(tree->right);
		if(l-r==2)
		{
			if(val< tree->left->val) tree=Rrotate(tree);
			else tree=LRrotate(tree);
		}
	}
	else
	{
		tree->right = insert(tree->right,val);
		int l=getheight(tree->left);
		int r=getheight(tree->right);
		if(r-l==2)
		{
			if(val > tree->right->val) tree=Lrotate(tree);
			else tree=RLrotate(tree);
		}
	}
	return tree;
}
vector<int> ans;
bool com=true;bool flag=false;
void levelorder(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *now=q.front();
		ans.push_back(now->val); 
		q.pop();
		if(now->left != NULL)
		{
			if(flag) com=false;
			q.push(now->left);
		}
		else flag=true;
		if(now->right != NULL)
		{
			if(flag) com=false;
			q.push(now->right);
		}
		else flag=true;
	}
}
int main()
{
	int T,n;
	cin>>T;
	struct node *root=NULL;
	while(T--)
	{
		scanf("%d",&n);
		root=insert(root,n);
	}
	levelorder(root);
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++)
	{
		printf(" %d",ans[i]);
	}
	if(com) printf("\nYES\n");
	else printf("\nNO\n");
	return 0;
}