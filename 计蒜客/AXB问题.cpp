#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char s1[505],s2[505];
	scanf("%s%s",s1,s2);
	int num1[505],num2[505];
	int l1=strlen(s1),l2=strlen(s2);
	for(int i=0;i<l1;i++) num1[i]=s1[l1-i-1]-'0';
	for(int i=0;i<l2;i++) num2[i]=s2[l2-i-1]-'0';
	int ans[1005];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{ 
			ans[i+j]+=num1[i]*num2[j];
		}
	}
	for(int i=0;i<=l1+l2;i++)
	{
		if(ans[i]>=10)
		{  
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	int i;
	for(i=1001;i>=0;i--)
	{
		if(ans[i]) break;
	}
	if(i<0) printf("0\n");
	else
	{
		for(;i>=0;i--) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
