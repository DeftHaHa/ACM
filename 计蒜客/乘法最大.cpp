#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string s=".98712365409451502137";
bool tag[25];
long long ans=0;
void dfs(int cnt,int pos)
{
	if(cnt==10)
	{        
		long long res=1,temp=0;
		for(int i=1;i<21;i++)
		{
			if(tag[i]||i==20)
			{
				temp=temp*10+(s[i]-'0');
				res*=temp;
				temp=0;
			}
			else temp=temp*10+(s[i]-'0');
		} //if(res>ans) {for(int i=1;i<=20;i++) cout<<tag[i];cout<<endl;cout<<res<<endl;}
		ans=max(ans,res);
		return;
	}
	for(int i=pos+1;i<20;i++)
	{
		tag[i]=true;
		dfs(cnt+1,i);
		tag[i]=false;
	}
}
int main()
{
	memset(tag,false,sizeof(tag));
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
