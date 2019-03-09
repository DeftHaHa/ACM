#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const string &a,const string &b)
{
	return a+b<b+a;
}
int main()
{
	string s[10005];
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>s[i];
	string ans;
	sort(s,s+N,cmp);
	for(int i=0;i<N;i++) 
	{
		ans+=s[i];
	}
	while(ans[0]=='0')
	{
		ans.erase(ans.begin());
	}
	if(ans.length()==0) cout<<0<<endl;
	else cout<<ans<<endl;
}