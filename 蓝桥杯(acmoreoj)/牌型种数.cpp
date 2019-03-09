#include<iostream>
#include<cstdio>
using namespace std;
int ans=0;
void dfs(int num,int tot)
{
	if(num>13) return;
	if(tot==13) 
	{
		ans++;
		return;
	}
	num+=1;
	for(int i=0;i<5;i++) dfs(num,tot+i);
}
int main()
{
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
