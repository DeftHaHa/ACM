#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int N;
	long long a[105],b[105];
	while(scanf("%d",&N)!=EOF)
	{
		
		for(int i=0;i<N;i++) scanf("%lld/%lld",&a[i],&b[i]);
		long long cm=b[0];
		for(int i=1;i<N;i++)
		{
			long long temp=gcd(cm,b[i]);//cout<<cm<<' '<<b[i]<<'='<<temp<<endl;
			cm=cm*b[i]/temp; 
		}
		long long suma=0,integer=0;
		for(int i=0;i<N;i++) suma+=cm/b[i]*a[i];
		bool negative=false;
		if(suma!=0)
		{
			if(suma<0)
			{
				suma=-suma;
				negative=true;
			}
			long long cd=gcd(suma,cm);
			suma/=cd;
			cm/=cd;
			integer=suma/cm;
			suma-=integer*cm;
		}
		if(suma==0&&integer==0) printf("0");
		else
		{
			if(suma==0&&negative) printf("-");
			if(integer!=0) printf("%lld ",integer);
			if(negative) printf("-");
			if(suma!=0||integer==0) printf("%lld/%lld",suma,cm);
		}
		printf("\n");
	}
	
	return 0;
}