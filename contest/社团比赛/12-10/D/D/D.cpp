#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	char s[10][10];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%c",&s[i][j]);
		}
		char ch=getchar();
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(s[i][j]=='#') printf("*");
			else printf("%c",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}