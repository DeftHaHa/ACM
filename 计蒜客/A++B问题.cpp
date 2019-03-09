#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s1[505],s2[505];
	scanf("%s",s1);
	scanf("%s",s2);
	int l1=strlen(s1),l2=strlen(s2);
	int num1[505],num2[505];
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	for(int i=0;i<l1;i++) num1[i]=s1[l1-i-1]-'0';
	for(int i=0;i<l2;i++) num2[i]=s2[l2-i-1]-'0';
	int i;
	for(i=0;i<max(l1,l2);i++)
	{
		num1[i]+=num2[i];   
		if(num1[i]>=10)
		{
			num1[i+1]++;
			num1[i]%=10;
		}
	}
	if(!num1[i]) i--;
	for(;i>=0;i--) printf("%d",num1[i]);
	printf("\n");
	return 0;
}
