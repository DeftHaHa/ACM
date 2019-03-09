#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int a[3];
bool vis[10];
int cnt=0,num1,num2;
void dfs(int floor)
{
	for(int i=1;i<=6;i++)
	{
		if(!vis[i])
		{
			a[floor]=i;
			vis[i]=true;
			if(floor<2) dfs(floor+1);
			else if(floor==2)
			{
				cnt++;
				if(cnt==90) num1=a[0]*100+a[1]*10+a[2];
				else if(cnt==100) num2=a[0]*100+a[1]*10+a[2];
			}
			vis[i]=false;
		}
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	dfs(0);
	cout<<num1<<' '<<num2<<' '<<num2-num1<<endl;
	return 0;
}
