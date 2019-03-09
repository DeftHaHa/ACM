#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char ans[1000005];
char ph[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
	int cnt=0;
	int N,R;
	cin>>N>>R;
	if(N<0)
	{
		printf("-");
		N=-N;
	}
	while(N)
	{
		ans[cnt++]=ph[N%R];
		N/=R;
	}
	if(cnt)
	{
		for(int i=cnt-1;i>=0;i--)
		{
			printf("%c",ans[i]);
		}
	}
	else printf("0");
	printf("\n");
	return 0;
}
