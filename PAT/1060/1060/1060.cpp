#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	char num1[1005],num2[1005];
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	int N;
	scanf("%d",&N);
	scanf("%s%s",num1,num2);
	int l1=strlen(num1),l2=strlen(num2);
	int p1=-1,p2=-1;
	for(int i=0;i<105;i++)
	{
		if(num1[i]=='.')
		{
			p1=i;
			break;
		}
	}
	if(p1==-1) p1=l1;
	if(p1==1&&num1[0]=='0') p1=0;
	for(int i=0;i<105;i++)
	{
		if(num2[i]=='.')
		{
			p2=i;
			break;
		}
	}
	if(p2==-1) p2=l2;
	if(p2==1&&num2[0]=='0') p2=0;
	char ans1[1005],ans2[1005];
	memset(ans1,0,sizeof(ans1));
	memset(ans2,0,sizeof(ans2));
	for(int i=0;i<min(N,l1);i++)
	{
		if(num1[i]!='.')ans1[i]=num1[i];
		else i--;
	}
	for(int i=0;i<min(N,l2);i++) 
	{
		if(num2[i]!='.')ans2[i]=num2[i];
		else i--;
	}
	bool ans=true;
	if(min(N,l2)!=min(N,l1)) ans=false;
	else
	{
		for(int i=0;i<min(l1,N);i++)
		{
			if(ans1[i]!=ans2[i])
			{
				ans=false;
				break;
			}
		}
	}
	if(p1!=p2) ans=false;
	if(ans)
	{
		printf("YES 0.%s",ans1);
		for(int i=1;i<=N-strlen(ans1);i++) printf("0");
		if(p1) printf("*10^%d\n",p1);
	} 
	else
	{
		printf("NO 0.%s",ans1);
		for(int i=1;i<=N-strlen(ans1);i++) printf("0");
		if(p1) printf("*10^%d",p1);
		printf(" 0.%s",ans2);
		for(int i=1;i<=N-strlen(ans2);i++) printf("0");
		if(p2) printf("*10^%d\n",p2);
	}
	return 0;
}