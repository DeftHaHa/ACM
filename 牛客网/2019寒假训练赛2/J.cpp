#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct C{
	long long b,len;
}c[100005];
bool cmp(C a,C b){
	return a.b < b.b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%lld",&c[i].len);
	for(int i = 0;i < n;i++) scanf("%lld",&c[i].b);
	sort(c,c+n,cmp);
	bool flag = true;
	long long T = 0;
	for(int i = 0,j = 0;i < n;i++){
	
		while(j<n&&(c[j].len == 0 || T + c[j].len <= c[i].b)){
			T += c[j].len; //	cout<<"$$$"<<i<<' '<<j<<' '<<c[i].b<<' '<<c[j].len<<endl;
			j++;
		}
	//	cout<<T<<' '<<i<<' '<<j<<endl;
		if(j <= i){
			flag = false;
			break;
		}
		T += 2;
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}
