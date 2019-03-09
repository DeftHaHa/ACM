#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[6];
bool flag2()
{
	int sum=0;
	for(int i=1;i<=5;i++)
	{
		sum+=num[i];
		if(num[i]>=5) return false;
	}
	if(sum>10) return false;
	return true;
}
bool flag3=false;
int res=100;
void dfs(int cnt,int pos,int sum)
{
	if(cnt>3||flag3) return;
	if(cnt==3&&sum%10==0)
	{
		flag3=true;
		res=sum;
	}
	for(int i=pos+1;i<=5;i++)
	{
		dfs(cnt+1,i,sum+num[i]);
	}
}
int main()
{
	for(int i=1;i<=5;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]>10) num[i]=10;
	}
	sort(num+1,num+6);
	int temp=num[3];
	if((num[2]==temp&&num[3]==temp&&num[4]==temp&&num[5]==temp)||
	(num[1]==temp&&num[2]==temp&&num[3]==temp&&num[4]==temp))
	{
		printf("quadra bomb orz\n");
	}
	else if(flag2()) printf("penta calf\n");
	else
	{
		dfs(0,0,0);
		int sum=0;
		for(int i=1;i<=5;i++) sum+=num[i];
		sum-=res;
		if(flag3)
		{
			if(sum%10==0) printf("you can you up\n");
			else printf("too young too simple:calf %d\n",sum%10);
		}
		else printf("gg\n");
	}
	return 0;
}
