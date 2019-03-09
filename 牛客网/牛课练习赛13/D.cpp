#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long num[1000005];  
int cnt=0;  
void dfs(int len,long long number)
{  
    if(len>10){  
    	return;
    } 
	num[cnt++]=number;
    dfs(len+1,number*10+4);
    dfs(len+1,number*10+7);
}
int main()
{
	
	int l,r;
    dfs(1,0);
    sort(num,num+cnt);
	while(~scanf("%d%d",&l,&r))
	{
		long long ans=0;
		for(int i=l;i<=r;i++)
		{
			int j=0;
			for(j=1;j<cnt;j++)
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
