#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int val;
	struct node *left,*right;
};
struct node* leftrotate(struct node *tree)
{
	struct node *temp=tree->right;
	tree->right=temp->left;
	temp->left=tree;
	return temp;
}
struct node* rightrotate(struct node *tree)
{
    struct node *temp = tree->left;
    tree->left = temp->right;
    temp->right = tree;
    return temp;
}
struct node* rightleftrotate(struct node *tree)
{
	tree->right = rightrotate(tree->right);
	return leftrotate(tree);
}
struct node* leftrightrotate(struct node *tree)
{
	tree->left = leftrotate(tree->left);
	return rightrotate(tree);
}
int getheight(struct node* tree)
{
	if(tree==NULL) return 0;
	else return max(getheight(tree->left),getheight(tree->right))+1;
}
struct node *insert(struct node *tree,int val)
{
	if(tree==NULL)
	{
		tree = new node();
		tree->val=val;
		tree->right=tree->left=NULL;
	}
	else if(val < tree->val)
	{
		tree->left=insert(tree->left,val);
		int l=getheight(tree->left);
		int r=getheight(tree->right);
		if(l-r==2)
		{
			if(val < tree->left->val) tree=rightrotate(tree);
			else tree=leftrightrotate(tree);
		}
	}
	else
	{
		tree->right= insert(tree->right,val);
		int l=getheight(tree->left);
		int r=getheight(tree->right);
		if(r-l==2)
		{
			if(val > tree->right->val) tree=leftrotate(tree);
			else tree=rightleftrotate(tree);
		}
	}
	return tree;
}
int main()
{
	int n,N;
	cin>>N;
	node *root=NULL;
	while(N--)
	{
		scanf("%d",&n);
		root=insert(root,n);
	}
	printf("%d\n",root->val);
	return 0;
}