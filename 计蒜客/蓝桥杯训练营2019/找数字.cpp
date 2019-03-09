#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
bool flag = false;
long long n,ans;
void dfs(int deep,long long num)
{
	if(deep > 19 || flag) return;
	if(num%n==0){
		flag = true;
		ans = num;
		return;
	}
	dfs(deep+1,num*10);
	dfs(deep+1,num*10+1);
}
int main()
{
	
	scanf("%lld",&n);
	dfs(1,1);
	printf("%lld\n",ans);	
	return 0;
}
