#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s2>>s1;
	int len1 = s1.length(),len2 = s2.length();
	int vis[256],vis2[256];
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	int cnt1 = 0,cnt2 = 0;
	for(int i = 0;i < len1;i++) vis[s1[i]]++;
	for(int i = 0;i < len2;i++) vis2[s2[i]]++;
	int res = 0,ned = 0;
	bool ok = true;
	for(int i = 0;i < 256;i++){
		if(vis[i] > vis2[i] ){
			ned += vis[i] - vis2[i];
			ok = false;
		}
		else res += vis2[i] - vis[i];
	}
	
	if(ok) printf("Yes %d\n",res);
	else printf("No %d\n",ned);
	
	return 0;
}
