#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int y,m,d,week;
	int fes[13][32];
	memset(fes,0,sizeof(fes));
	cin>>y;
	fes[1][1] = fes[5][1]  = fes[12][25] = 1;
	fes[10][1] = 3;
	for(int i = 0;i < 4;i++)
	{
		cin>>m>>d;
		fes[m][d] = 1;
		if(!i) fes[m][d]+=2;
	}
	cin>>week;
	if(week==7) week=0;
	int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((y%4==0&&y%100!=0)||y%400==0) month[2] = 29;
	int ans = 0;
	int temp = 0;
	for(int i = 1;i <= 12;i++)
	{
		for(int j = 1;j <= month[i];j++)
		{
			temp += fes[i][j];
			if(week==0||week==6||temp)
			{
				ans++;
				if(temp) temp--;
			}
			week = (week+1)%7;
		}
	}
	cout<<ans<<endl;

	return 0;
}
