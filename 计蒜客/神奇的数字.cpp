#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int ans=0;
	int vis[10],vis2[10];
	for(long long i=10;i<=1e8;i*=10)
	{
		for(long long num=i/10;num<i*10;num++)
		{
			if(num*6/i) break;
			memset(vis,0,sizeof(vis));
			long long temp=num;
			while(temp)
			{
				vis[temp%10]++;
				temp/=10;
			}
			bool flag=true;
			for(int j=2;j<7;j++)
			{
				temp=j*num;
				memset(vis2,0,sizeof(vis2));
				while(temp)
				{
					vis2[temp%10]++;
					temp/=10;
				}
				for(int k=0;k<10;k++)
				{
					if(vis[k]!=vis2[k])
					{
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
