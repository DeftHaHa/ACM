#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int N;
	char pu[10][5005];
	char ans[5005];
	while(~scanf("%d",&N))
	{
		char ch=getchar();
		for(int i=1;i<=9;i++)
		{
			for(int j=0;j<N;j++) scanf("%c",&pu[i][j]);
			ch=getchar();
		}
		
		for(int j=0;j<N;j++)
		{
			if(pu[8][j]=='o'||pu[1][j]=='o') printf("F");
			else if(pu[6][j]=='o') printf("A");
			else if(pu[5][j]=='o') printf("B");
			else if(pu[4][j]=='o') printf("C");
			else if(pu[3][j]=='o') printf("D");
			else if(pu[2][j]=='o') printf("E");
			else if(pu[7][j]=='o') printf("G");
			else if(pu[9][j]=='o') printf("F");
			else if(pu[1][j]=='|') printf("|");
			
		}
		printf("\n");
	}
	return 0;
}




