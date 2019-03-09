#include<iostream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
ll mod = 13131313;
map<ll,int> hash;
char s[100005][12];
ll gethash(char *s){
	int len = strlen(s);
	ll sum = 0;
	for(int i = 0;i < len;i++){
		sum = sum*29 + (s[i] - 'a');
	}
	return sum;
}
int main()
{
	char s2[15];
	int cnt = 0;
	memset(s,0,sizeof(s));
	while((s[++cnt][0] = getchar())!='\n'){
		scanf("%s%s",s[cnt]+1,s2);
		hash[gethash(s2)] = cnt;
		//printf("%s %s\n",s[cnt],s2);
		getchar();
	}
	while(~scanf("%s",s2)){
		int len = strlen(s2);
		int k = hash[gethash(s2)];
		if(!k) printf("eh\n");
		else printf("%s\n",s[k]);
	}
	return 0;
}
/*
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/ 
