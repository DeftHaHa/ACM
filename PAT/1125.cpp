#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int len[10005],N;
int main(){
	cin>>N;
	for(int i = 0;i < N;i++) scanf("%d",&len[i]);
	sort(len,len+N);
	double ans = (double)len[0];
	for(int i = 1;i < N;i++){
		ans += (double)len[i];
		ans /= 2.0;
	}
	printf("%d\n",(int)ans);
	return 0;
}
