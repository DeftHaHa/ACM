#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
	int N,M,K,Q;
	int ans[1005],time[1005];
	bool vis[1005];
	int tnow[25];
	queue<int> q[25];
	while(cin>>N>>M>>K>>Q)
	{
		memset(vis,true,sizeof(vis));
		for(int i=1;i<=K;i++)
		{
			cin>>time[i];
		}
		for(int i=1;i<=N;i++) tnow[i]=480;
		for(int i=1;i<=K;)
		{
			int mintot=M+1;
			int minend=0x3f3f3f3f;
			for(int j=1;j<=N;j++)
			{
				if(q[j].empty())
				{
					minend=0;
					break;
				}
				else if(ans[q[j].front()]<minend)
					minend=ans[q[j].front()];
			}
			for(int j=1;j<=N;j++)
			{
				if(q[j].empty()) break;
				else if(ans[q[j].front()]==minend)
				{
					q[j].pop();
				}
			}
			bool flag=true;
			while(flag)
			{
				flag=false;
				mintot=M+1;
				for(int j=1;j<=N;j++)
				{
					int s=q[j].size();
					if(s<M)
					{
						flag=true;
						if(s<mintot)
							mintot=s;
					}
				}
				for(int j=1;j<=N;j++)
				{
					if(q[j].size()==mintot)
					{
						if(tnow[j]>=1020)  vis[i]=false;
						tnow[j]=time[i]+tnow[j];
						ans[i]=tnow[j];
						q[j].push(i);
						i++;
						if(i>K)
						{
							flag=false;
							break;
						}
					}
				}
			}
			
		}
		while(Q--)
		{
			int qu;
			cin>>qu;
			if(!vis[qu]) cout<<"Sorry"<<endl;
			else printf("%02d:%02d\n",ans[qu]/60,ans[qu]%60);
		}
		for(int j=1;j<=N;j++) while(!q[j].empty()) q[j].pop();
	}
	return 0;
}