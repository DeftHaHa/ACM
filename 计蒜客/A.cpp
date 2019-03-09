#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int a[4] = {2,0,1,9};
ll ans = 0;
bool Find(string s){
	for(int i = 0;i < 6;i++){
		if(s[i]=='2'&&s[i+1]=='0'&&s[i+2]=='1'&&s[i+3]=='9') return true;
	}
	return false;
}
void dfs(int deep,string s)
{
	if(deep == 10)
	{
		if(Find(s)) ans++;
		return;
	}
	for(int i = 0;i <= 9;i++){
		dfs(deep+1,s+(char)('0'+i));
	}
}
int main()
{
	
	
	dfs(1,"");
	cout<<ans<<endl;
	return 0;
}
