#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll mod = 13131313;
int cnt[mod+1];
ll key[100005];
char s[15];
int main()
{
	memset(cnt,0,sizeof(cnt));
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%s",s);
		int len = strlen(s);
		ll k = 0;
		for(int j = len-1;j >= 0;j--){
			k = (k*27 + s[j]-'a'+1)%mod;
			cnt[k]++;
		}
		key[i] = k;
	}
	for(int i = 0;i < n;i++){
		printf("%d\n",cnt[key[i]]);
	}
	return 0;
}
