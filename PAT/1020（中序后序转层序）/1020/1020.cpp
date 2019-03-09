#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int post[35],in[35];
int N;
vector<int> v[35];
void find(int r,int left,int right,int level)
{
	if(left>right) return;
	int root=post[r],i;
	for(i=left;i<=right;i++)
	{
		if(in[i]==root) break;
	}
	v[level].push_back(root);
	find(r-(right-i+1),left,i-1,level+1); //左子树根节点=当前根节点-右字数自述长度
	find(r-1,i+1,right,level+1);
}
int main()
{
	cin>>N;
	{
		for(int i=0;i<N;i++) cin>>post[i];
		for(int i=0;i<N;i++) cin>>in[i];
		find(N-1,0,N-1,0);
		cout<<v[0][0];
		for(int i=1;i<35;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				cout<<' '<<v[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}