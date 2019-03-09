#include<cstdio>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
bool is_prime[1000005];
int prime[4005],tot;
void euler(){
	tot = 0;
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i = 2;i<= 100000;i++){
		if(is_prime[i]) prime[++tot] = i;
		if(tot==4000) break;
		for(int j = 1;j <= tot && i*prime[j]<=100000;j++ ){
			is_prime[i*prime[j]] = false;
			if(i%prime[j]==0) break;
		}
	}
}
int main()
{
	euler();
	for(int i = 1;i <= 2000;i++){
		printf("%d\n",prime[i]*prime[4000-i]);
	}
	
	return 0;
}
