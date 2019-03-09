#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,k;
char s[200005];
int a[200005],temp[200005];
typedef long long ll;
bool cmp(int a,int b){
	return a >= b;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	scanf("%s",s);
	ll ans = 0;
	for(int i = 0,j = 1;i < n;){
		while(j < n && s[i] == s[j]) j++;
		int r = j;
		if(j - i > k) nth_element(a+i,a+i+k-1,a+j,cmp),r=i+k;
		for(int t = i;t < r;t++) ans += a[t];	
		i = j;
	}
	printf("%I64d\n",ans);
	return 0;
}
