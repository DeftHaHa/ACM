#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d",&n);
	ll k,x;
	while(n--){
		scanf("%I64d%I64d",&k,&x);
		printf("%I64d\n",(k-1)*9+x);
	}
	return 0;
}
