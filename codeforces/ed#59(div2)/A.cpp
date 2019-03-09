#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
bool cmp(string a,string b){
	int lena = a.length(),lenb = b.length();
	if(lena!=lenb) return lena>lenb;
	return a>b;
}
int main()
{
	int q;
	scanf("%d",&q);
	char s[305];
	int len;
	while(q--){
		scanf("%d%s",&len,s);
		string ans[305];
		int cnt = 0;
		string last = "0",now = "";
		for(int i = 0;i < len;i++){
			now += s[i];
			if(cmp(now,last)){
				ans[cnt++] = now;
				last = now;
				now.clear();
			}
			else if(i==len-1){
				ans[cnt-1]+=now;
			}
		}
		if(cnt>1){
			puts("YES");
			printf("%d\n",cnt);
			cout<<ans[0];
			for(int i = 1;i < cnt;i++) cout<<' '<<ans[i];
			printf("\n");
		}
		else puts("NO");
	}
	return 0;
}
