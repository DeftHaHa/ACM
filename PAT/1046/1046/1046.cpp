#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int N,d[100005],t;
	d[1]=0;
	cin>>N;
	for(int i=2;i<=N;i++)
	{
		scanf("%d",&t);
		d[i]=d[i-1]+t;
	}
	cin>>t;
	int M,u,v,sum=d[N]+t;
	cin>>M;
	while(M--)
	{
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		cout<<min(d[v]-d[u],d[u]+sum-d[v])<<endl;
	}
	return 0;
}