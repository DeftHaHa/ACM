#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool prim[100005];
int main()
{
	memset(prim,true,sizeof(prim));
	for(int i=2;i*i<=100000;i++)
	{
		if(prim[i])
		{
			for(int j=i*i;j<=100000;j+=i)
			{
				prim[j]=false;
			}
		}
	}
	long int N;
	scanf("%ld",&N);
	printf("%ld=",N);
	if(N<2) printf("%d",N);
	bool flag=false;
	for(int i=2;N>=2;i++)
	{
		if(prim[i]&&N%i==0)
		{
			int tot=0;
			while(N%i==0)
			{
				tot++;
				N/=i;
			}
			if(flag) printf("*");
			printf("%d",i);
			if(tot>1) printf("^%d",tot);
			flag=true;
		}
	}
	
	cout<<endl;
	return 0;
}
