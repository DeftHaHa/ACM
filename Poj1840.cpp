#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int MAXN = 12500000;
const int mod = 33131313;
char hash[mod+5];
int main()
{
	int a[5];
	scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	memset(hash,0,sizeof(hash));
	for(int i = -50;i <= 50;i++){
		if(i)
		for(int j = -50;j <= 50;j++){
			if(j){
				int pro = -(i*i*i*a[0] + j*j*j*a[1]);
				hash[(pro+mod)%mod]++;
			}
		}
	}
	int ans = 0;
	for(int i = -50;i <= 50;i++){
		if(i)
		for(int j = -50;j <= 50;j++){
			if(j)
			for(int k = -50;k <= 50;k++){
				if(k){
					int pro = a[2]*i*i*i + a[3]*j*j*j + a[4]*k*k*k;
					ans += (int)hash[(pro+mod)%mod];
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
