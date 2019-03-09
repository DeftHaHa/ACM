#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	char s[200005];
	scanf("%d",&n);
	getchar();
	for(int i = 0;i < n;i++) scanf("%c",&s[i]);
	int tag = n-1;
	for(int i = 1;i < n;i++)
	{
		if(s[i] < s[i-1])
		{
			tag = i-1;
			break;
		}
	}
	for(int i = 0;i < n;i++) if(i != tag) printf("%c",s[i]);
	printf("\n");
	return 0;
}
