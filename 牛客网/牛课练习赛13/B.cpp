#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
long long num[1000005];  
int cnt=0;
/*
queue<long long> q;
void bfs()
{
	q.push(0);
	while(!q.empty())
	{
		long long temp=q.front();
		q.pop();
		num[cnt++]=temp;
		if(cnt>1023) return;
		q.push(temp*10+4);
		q.push(temp*10+7);
	}
}*/
void dfs(int len,long long number)
{  
    if(len>11){  
    	return;
    } 
	num[cnt++]=number;
    dfs(len+1,number*10+4);
    dfs(len+1,number*10+7);
}
int main()
{
	
	long long l,r;
    dfs(1,0);
    sort(num,num+cnt);
	while(~scanf("%lld%lld",&l,&r))
	{
		long long ans=0;
		int j=lower_bound(num,num+cnt,l)-num;
		for(long long i=l;i<=r;i++)
		{
			for(;j<cnt;j++)
			{
				if(num[j]>=i)
				{
					ans+=num[j];
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
