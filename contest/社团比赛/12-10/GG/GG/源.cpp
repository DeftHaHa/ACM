#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
bool prim[10005];
int main()
{
	memset(prim,true,sizeof(prim));
	prim[2]=true;
	for(int i=2;i<=100;i++)
	{
		if(prim[i])
		{
			for(int j=2*i;j<=10000;j+=i) prim[j]=false;
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1000;i<10000;i++)
	{
		if(prim[i])
		{
			bool flag=false;
			int temp=i;
			while(temp)
			{
				if(temp%10==n)
				{
					flag=true;
					break;
				}
				temp/=10;
			}
			if(flag) printf("%d\n",i);
		}
		
	}
	return 0;
}