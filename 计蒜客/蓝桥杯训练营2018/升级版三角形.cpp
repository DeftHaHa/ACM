#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char ch;
	scanf("%c",&ch);
	int deep;
	if(ch>='A'&&ch<='Z')
	{
		deep = ch-'A'+1;
		ch = 'A';
	}
	else
	{
		deep = ch-'1'+1;
		ch = '1';
	}
	for(int i = 1;i <= deep ;i++)
	{
		for(int j = 0;j < deep-i;j++) printf(" ");
		for(int j = 0;j < i;j++) printf("%c",ch+j);
		for(int j = i-2;j >= 0;j--) printf("%c",ch+j);
		printf("\n");
	}
	return 0;
 } 
