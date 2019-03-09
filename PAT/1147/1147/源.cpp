#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool Min,Max;
int M,N;

int tra[2005],len;
int tree[10005];
void post(int root)
{
	int l=root*2,r=root*2+1;
	if(l<=N)
	{
		if(tree[root]>tree[l]) Max=true;
		if(tree[root]<tree[l]) Min=true;
		post(l);
	}
	if(r<=N)
	{
		if(tree[root]>tree[r]) Max=true;
		if(tree[root]<tree[r]) Min=true;
		post(r);
	}
	tra[len++]=tree[root];
}
int main()
{
	cin>>M>>N;
	while(M--)
	{
		for(int i=1;i<=N;i++) scanf("%d",&tree[i]);
		Min=Max=false;
		len=0;
		post(1);
		if(Max&&Min) printf("Not Heap\n");
		else if(Max) printf("Max Heap\n");
		else if(Min) printf("Min Heap\n");
		cout<<tra[0];
		for(int i=1;i<N;i++) printf(" %d",tra[i]);
		cout<<endl;
	}
	system("pause");

	return 0;
}