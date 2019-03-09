#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int y,m,d;
	freopen("DATA.txt","r",stdin);
	int ans=0;
	int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=1;i<=20;i++)
	{
		scanf("%d-%d-%d",&y,&m,&d);
		int sum=311;
		for(int j=2018;j<y;j++)
		{
			if((j%4==0&&j%100!=0)||j%400==0) sum+=366;
			else sum+=365;
		}
		for(int j=1;j<m;j++) sum+=md[j];
		sum+=d;
		if((y%4==0&&y%100!=0)||y%400==0)
		{
			if(m>2) sum+=1;
		}
		ans+=sum;
	}
	cout<<ans<<endl;
	return 0;
}
