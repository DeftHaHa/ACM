#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int y,m,d,k;
	cin>>y>>m>>d>>k;
	int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i = y ; ;i++)
	{
		if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0)) month[2] = 29;
		else month[2] = 28;
		int j = 1;
		if(i==y) j = m;
		for(;j <= 12;j++)
		{
			if(k+d<=month[j])
			{
				printf("%d-%02d-%02d\n",i,j,k+d);
				return 0;
			}
			k-=month[j];
		}
	}
	
	
	return 0;
}
