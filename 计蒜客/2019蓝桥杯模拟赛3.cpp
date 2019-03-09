#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans = 0;
int SUM = 6;
void dfs(int n,int sum){
	if(sum > SUM) return;
	if(sum==SUM){
		ans ++;
		return;
	}
	for(int i = n;i <= 10;i++){
		dfs(i,sum+i);
	}
}
int main()
{
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}

