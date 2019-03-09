#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1000005;
int prime[maxn],tot = 0;
bool is_prime[maxn];
void euler(int n){
	memset(is_prime,true,sizeof(is_prime));
	for(int i = 2;i <= n;i++){
		if(is_prime[i]) prime[++tot] = i;
		for(int j = 1;j <= tot && prime[j]*i <= n;j++){
			is_prime[i*prime[j]] = false;
			if(i%prime[j]==0) break;
		}
	}
}
int main()
{
	int t,n;
	scanf("%d",&t);
	euler(1000000);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= tot;i++){
			if(is_prime[n-prime[i]]){
				printf("%d %d\n",prime[i],n-prime[i]);
				break;
			}
		}
	}
	return 0;
}
