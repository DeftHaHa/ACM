#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int b[260];
	memset(b,0,sizeof(b));
	int k;
	scanf("%d",&k);
	string s;
	cin>>s;
	int len = s.length();
	int t = 1;
	string ans = "";
	for(int i = 1;i < len;i++){
		if(s[i] == s[i-1]){
			t++;
			if(t==k && b[s[i]] == 0) b[s[i]] = 2;
		}
		else{
			if(t<k) b[s[i-1]] = 1;
			t = 1;
		}
	}
	if(b[s[0]]!=2) ans += s[0];
	t = 1;
 	for(int i = 1;i < len;i++){
		if(s[i] == s[i-1]){
			t++;
			if(t%k==0 && b[s[i]]==2){
				ans += s[i];
			}
		}
		else{
			t = 1;
		}
		if(b[s[i]]!=2) ans+=s[i];
	}
	bool ok = false;
	for(int i = 0;i < len;i++) if(b[s[i]]==2) ok = true;
	if(ok){
		for(int i = 0;i < len;i++) if(b[s[i]]==2) printf("%c",s[i]),b[s[i]] = 0;
		puts("");
	}
	cout<<ans<<endl;
	return 0;
}
