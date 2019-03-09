#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,bool> vis;
int main()
{
	int M,N,S;
	scanf("%d%d%d",&M,&N,&S);
	string s[1005];
	for(int i = 1;i <= M;i++) cin>>s[i];
	if(S>M) puts("Keep going...");
	else{
		int cnt = N-1;
		for(int i = S;i <= M;i++){
			if(!vis[s[i]]){
				cnt++;
				if(cnt==N){
					printf("%s\n",s[i].c_str());
					vis[s[i]] = true;
					cnt = 0;
				}
			}
		}
	}
	return 0;
}
