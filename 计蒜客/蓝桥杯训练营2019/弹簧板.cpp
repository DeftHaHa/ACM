#include<iostream>
using namespace std;
int n,a[205],b[205];
int ans = 0x3f3f3f3f;
void dfs(int deep,int dis){
	
	if(dis > n){
		ans = min(ans,deep);
		return;
	}
	dfs(deep+1,dis+a[dis]);
	dfs(deep+1,dis+b[dis]);
}
int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&b[i]);
	dfs(0,1);
	cout<<ans<<endl;
	return 0;
}
