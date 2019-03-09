#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		char mat[35][35];
		memset(mat,0,sizeof(mat));
		cin>>n>>m;
		char ch=getchar();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				scanf("%c",&mat[i][j]);
			ch=getchar();
		}
		string s;
		cin>>s;
		int cnt=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='R') cnt++;
			else cnt--;
		}
		int k=cnt%4;
		k=(k+4)%4;
		char ans[35][35];
		memset(ans,0,sizeof(ans));
		while(k--)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(mat[i][j]=='-') ans[j][n-i+1]='|';
					else if(mat[i][j]=='|') ans[j][n-i+1]='-';
					else ans[j][n-i+1]=mat[i][j];
				}
			}
			swap(n,m);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					mat[i][j]=ans[i][j];
				}
			}
		}
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				printf("%c",mat[i][j]);
			}
			printf("\n");
		}
		cout<<endl;
	}
	
	return 0;
}
