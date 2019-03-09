#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n , m;
	scanf("%d%d",&n,&m);
	int ans = 0;
	for(int i = n;i <= m;i++){
		bool flag = true;
		int t = i;
		while(t){
			if(t%10==4) flag = false;
			t/=10;
		}
		if(flag) ans ++;
	}
	printf("%d\n",ans);
	return 0;
}
