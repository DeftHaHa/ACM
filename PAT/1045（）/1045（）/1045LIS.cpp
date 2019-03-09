#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main()
{
	map<int,int> m;
	int N,M,L;
	cin>>N>>M;
	int t;
	for(int i=0;i<M;i++)
	{
		scanf("%d",&t);
		m[t]=i;
	}
	cin>>L;
	int s[10005],tot=0;
	while(L--)
	{
		cin>>t;
		if(m.count(t))
		{
			s[++tot]=m[t];
		}
	}
	int temp[10005],len=1;
	temp[1]=s[1];
	for(int i=2;i<=tot;i++)
	{
		if(s[i]>=temp[len])
		{
			temp[++len]=s[i];
		}
		else
		{
			int pos=upper_bound(temp+1,temp+len,s[i])-temp;//返回第一个大于s[i]的地址
			temp[pos]=s[i];
		}
	}
	cout<<len<<endl;
	return 0;
}