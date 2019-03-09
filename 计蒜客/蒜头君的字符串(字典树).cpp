#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int ch[1000005][28];
int cnt[1000005];
int tot=0;
void insert(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(ch[p][s[i]-'a']==-1)
		{
			ch[p][s[i]-'a']=++tot;
		}
		p=ch[p][s[i]-'a'];
		cnt[p]++;
	}
}
int main()
{
	memset(ch,-1,sizeof(ch));
	memset(cnt,0,sizeof(cnt));
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		cin>>s;
		insert(s);
	} 
	int ans=0;
	for(int i=1;i<=tot;i++) if(cnt[i]>1) ans++;
	cout<<ans<<endl;
	return 0;
}
