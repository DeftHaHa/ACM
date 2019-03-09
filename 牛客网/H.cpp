#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1005;
int mod;
int mat[maxn][maxn],ans[maxn][maxn];
int main()
{
	int N;
	while(~scanf("%d%d",&N,&mod))
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				scanf("%d",&mat[i][j]);
				mat[i][j]%=mod;
			}
		}  
		bool flag=true;
		int ansii=mat[1][1];
		for(int i=1;i<=N;i++)
		{
			if(mat[i][i]!=ansii)
			{
				flag=false;
				break;
			}
			else ans[i][i]=0;
			if(flag)
			for(int j=i+1;j<=N;j++)
			{
				int temp=mat[i][j]-mat[j][i];  //cout<<i<<' '<<j<<'='<<temp<<endl;
				if(temp&1)
				{
					flag=false;
					break;
				}
				else
				{
					ans[i][j]=temp/2;
					ans[j][i]=-ans[i][j];
				}
			}
		}
		if(!flag) printf("Impossible\n");
		else
		{
			for(int i=1;i<=N;i++)
			{
				printf("%d",ans[i][1]);
				for(int j=2;j<=N;j++)
				{
					printf(" %d",ans[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
