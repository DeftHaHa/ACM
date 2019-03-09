#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 16000000;
int N,NC;
char s[MAXN+5];
bool vis[MAXN+5];
int hash[256]; 
int main()
{
	scanf("%d%d%s",&N,&NC,s);
	int len = strlen(s);
	int cnt = 0;
	memset(hash,0,sizeof(hash));
	for(int i = 0;i < len;i++){
		if(!hash[s[i]]){
			hash[s[i]] = ++cnt;
			if(cnt==NC) break;
		}
	}
	int num = 0;
	memset(vis,false,sizeof(vis));
	int mar = 1;
	for(int i = 0;i < N;i++){
		num = num*NC + hash[s[i]];
		mar *= NC;
	}
	mar /= NC;
	vis[num] = true;
	int ans = len>=N ? 1:0;
	for(int i = 0;i < len - N;i++){
		num = (num- hash[s[i]] * mar)*NC + hash[s[i+N]];
		if(!vis[num]){
			vis[num] = true;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
