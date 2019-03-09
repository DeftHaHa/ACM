#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int s[10];
	bool Find = false;
	for(int i = 10001;i <= 999999;i++){
		int t = i,sum = 0,len = 0;
		while(t){
			s[++len] = t%10;
			sum += s[len];
			t/=10;
		}
		bool flag = true;
		for(int l=1,r=len;l < r;l++,r--){
			if(s[l]!=s[r]){
				flag = false;
				break;
			}
		}
		if(flag && sum == n) {
			printf("%d\n",i); 
			Find = true;
		}
	}
	if(!Find) printf("-1\n");
	return 0;
}
