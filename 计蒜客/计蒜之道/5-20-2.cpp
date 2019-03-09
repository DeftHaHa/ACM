#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m;
int t[30][30];
bool judge(int a[])
{
	for(int i=1;i<=m;i++)
	{
		int tag;
		for(int j=0;j<n;j++)
		{
			if(a[j]==t[i][1])
			{
				tag=j;
				break;
			}
		}
		if(j>=n) return false;
		for(int j=tag+1,k=2;k<=t[i][0]&&k<n;j++,k++)
		{
			if(a[j]!=t[i][k]) return false;
		}
	}
	return true;
}
int main()
{
	
	scanf("%d%d",&n,&m);
	int a[10]={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<n;i++) a[i]=i+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t[i][0]);
		for(int j=1;j<=t[i][0];j++) scanf("%d",&t[i][j]);
	}
	bool flag=false;
	do
	{
		
		if(judge(a))
		{
			flag=true;
			for(int i=0;i<n;i++) printf("%d",a[i]);
			cout<<endl;
			break;
		}
		
	}while(next_permutation(a,a+n));
	if(!flag) cout<<-1<<endl;
	return 0;
}
