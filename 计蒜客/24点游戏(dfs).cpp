#include<iostream>
#include<cstring>
using namespace std;
int card[55];
int ans=0;
void dfs(int id,int sum)
{
	if(sum==24) ans++;
	else if(sum>24) return;
	for(int i=id+1;i<=52;i++)
	{
		dfs(i,sum+card[i]);
	}
}
int main()
{
	for(int i=0;i<52;i++) card[i+1]=i/4+1;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
