#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int maxn=27;
int len[30]={10,7,9,10,13,23,2,3,31,1,5,6,7,8,9,6,6,5,4,1,2,3,3,11,13,12,6};
int aim=0,CNT;
bool cmp(const int &a,const int &b)
{
	return a>b;
}
bool vis[30];
bool dfs(int cnt,int sum,int pos)
{
	if(cnt==CNT) return true;
	if(sum==aim) return dfs(cnt+1,0,0);
	for(int i=pos;i<maxn;i++)
	{
		if(!vis[i]&&sum+len[i]<=aim)
		{
			vis[i]=true;
			if(dfs(cnt,sum+len[i],i+1)) return true;
			vis[i]=false;
			if(sum==0) return false;
			while(i+1<maxn&&len[i+1]==len[i]) i++;
		}
	}
	return false;
}
int main()
{
	int sum=0;
	sort(len,len+30,cmp);
	for(int i=0;i<maxn;i++) sum+=len[i];
	for(int i=27;i>=1;i--)
	{
		if(sum%i==0)
		{  cout<<"dfs"<<i<<endl;
			aim=sum/i;
			CNT=i;
			memset(vis,false,sizeof(vis));
			if(dfs(0,0,0))
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
