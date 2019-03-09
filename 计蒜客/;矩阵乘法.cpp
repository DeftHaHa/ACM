#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int ans[3][3],temp[3][3];
void combi(int temp[][3],int c[][3])
{
	memset(ans,0,sizeof(ans));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				ans[i][j]+=temp[i][k]*c[k][j];
			}
				
		}
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp[i][j]=ans[i][j];
}
int main()
{
	memset(ans,0,sizeof(ans));
	for(int i=0;i<3;i++) temp[i][i]=1;
	for(int i=0;i<5;i++)
	{
		combi(temp,c); cout<<"===="<<i+1<<endl;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				cout<<ans[i][j]<<' ';
			cout<<endl;
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
