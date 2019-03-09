#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool up[1005][1005],str[1005][2005];
int main()
{
	int X,Y,Z,N;
	while(~scanf("%d%d%d%d",&X,&Y,&Z,&N))
	{
		int x,y,z;
		memset(up,0,sizeof(up));
		memset(str,0,sizeof(str));
		while(N--)
		{
			scanf("%d%d%d",&x,&y,&z);
			str[y][x]=true;
			str[y][z+X+1]=true;
			up[z][x]=true;
		}
		for(int i=Y;i>=1;i--)
		{
			for(int j=1;j<=X+Z+1;j++)
			{
				if(j==X+1) printf(" ");
				else if(str[i][j]) printf("x");
				else printf(".");
			}
			printf("\n");
		}
		printf("\n");
		for(int i=1;i<=Z;i++)
		{
			for(int j=1;j<=X;j++)
			{
				if(up[i][j]) printf("x");
				else printf(".");
			}
			printf("\n");
		}
	}

}
