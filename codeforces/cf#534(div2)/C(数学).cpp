#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[1005];
	scanf("%s",s);
	int len = strlen(s);
	int cnt0 = 0,cnt1 = 0;
	for(int i = 0;i < len;i++){
		if(s[i]=='0'){
			if(cnt0 == 0) puts("1 1");
			else puts("3 1");
			cnt0 = (cnt0+1)%2;
		}
		else {
			printf("%d 3\n",cnt1+1);
			cnt1 = (cnt1+1)%4;
		}
	}
	return 0;
}
