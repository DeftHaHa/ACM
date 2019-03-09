#include<bits/stdc++.h>
using namespace std;
const int n=4;
const int m=4;//???4*4 
int a[n+5][m+5];//????? 
bool t[30];//2~16?,?????????????true,?????false; 
int x2,y2;//??"1"???; 
int xx,yy;
void dfs(int x,int y)
{	yy=y+1;
	xx=x;
	if(yy>m)
	{
		yy=1;
		xx++;
	}//???????????; 
	if(x==x2&&y==y2)//??????????"1"???,???????; 
	{
		dfs(xx,yy);
		return ;
	}
	if(x>n)//?????? 
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<a[i][j]<<" ";
			}
			puts("");
		}
		puts("");
		return ;
	}//?? 

	
	int flag=0;
	for(int i=2;i<=16;i++)
	{
		if(!t[i])//?????? 
		{
			t[i]=true;//????????? 
			a[x][y]=i;//????????? 
			if(y==4)
			{
				if(a[x][1]+a[x][2]+a[x][3]+a[x][4]!=34)
					flag=1;
			}
			if(x==2&&y==2)
			{
				if(a[1][1]+a[1][2]+a[2][1]+a[2][2]!=34)
					flag=1;
			}
			if(x==3&&y==3)
			{
				if(a[2][2]+a[2][3]+a[3][2]+a[3][3]!=34)
					flag=1;
			}
			if(x==2&&y==4)
			{
				if(a[1][3]+a[1][4]+a[2][3]+a[2][4]!=34)
					flag=1;
			}
			if(x==4&&y==2)
			{
				if(a[3][1]+a[3][2]+a[4][1]+a[4][2]!=34)
					flag=1;
			}
			if(x==4&&y==4)
			{
				if(a[3][3]+a[3][4]+a[4][3]+a[4][4]!=34)
					flag=1;
				if(a[1][1]+a[4][1]+a[1][4]+a[4][4]!=34)
					flag=1;
				if(a[1][1]+a[2][2]+a[3][3]+a[4][4]!=34)
					flag=1;
				
			}
			if(x==4)
			{
				if(a[1][x]+a[2][x]+a[3][x]+a[4][x]!=34)
					flag=1;
				
			}
			if(x==4&&y==1)
			{
				if(a[1][4]+a[2][3]+a[3][2]+a[4][1]!=34)
					flag=1;
			}//?????flag??1,??????????? 
			if(flag==0)
				dfs(xx,yy);
			t[i]=false;//?? 
		}
	}// 
}
int main()
{
	
	cin>>x2>>y2;
	a[x2][y2]=1;//?x2,y2????1; 
	dfs(1,1);//???1,1?? 
} 
