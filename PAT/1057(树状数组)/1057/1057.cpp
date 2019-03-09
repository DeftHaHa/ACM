#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ta[100005];
int lowbit(int x)
{
	return x&-x;
}
void add(int addr,int num)
{
	for(int i=addr;i<=100000;i+=lowbit(i))
	{
		ta[i]+=num;
	}
}
int sum(int addr)
{
	int ans=0;
	for(int i=addr;i>0;i-=lowbit(i))
		ans+=ta[i];
	return ans;
}
int mid(int x)
{
	int index=(x+1)/2;
	int ans;
	int left=1,right=100000,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		int now=sum(mid);
		if(now>=index)
		{
			ans=mid;
			right=mid-1;
		}
		else left=mid+1;
	}
	return ans;
}
int main()
{
	int N;
	int s[100005],top=0;
	int num;
	memset(ta,0,sizeof(ta));
	char c[15];
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",c);
		if(c[1]=='u')
		{
			scanf("%d",&num);
			s[++top]=num;
			add(num,1);
		}
		else if(c[1]=='o')
		{
			if(top==0) printf("Invalid\n");
			else
			{
				int t=s[top--];
				printf("%d\n",t);
				add(t,-1);
			}
		}
		else if(c[1]=='e')
		{
			if(top==0) printf("Invalid\n");
			else 
			{
				printf("%d\n",mid(top));
			}
		}
	}
	return 0;
}