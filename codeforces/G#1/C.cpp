#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	int a;
	while(q--)
	{
		scanf("%d",&a);
		int t = a,cnt = 0;
		while(t){
			cnt++;
			t >>= 1;
		}
		int x = a^((1<<cnt)-1);
		if(x) printf("%d\n",(1<<cnt)-1);
		else {
			int ans = 1;
			for(int i = 2;i*i <= a;i++){
				if(a%i==0){
					ans = max(ans,max(i,a/i));
					break;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
} 
