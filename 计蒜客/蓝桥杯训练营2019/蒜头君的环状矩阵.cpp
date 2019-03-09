#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mat[105][105];
ll sumc[105][105];
int main()
{
	
	int n,m;
	cin>>n>>m;
	memset(sumc,0,sizeof(sumc));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&mat[i][j]);
			sumc[i][j]=mat[i][j]+sumc[i-1][j];
		}
	}		
	ll ans=mat[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n+i-1;j++)
		{
		
			if(j > n){
				for(int k=1;k<=m;k++){
						ll sum=0;
					for(int l = 0;l < m;l++){
						int col = (l+k)%m;
						if(col==0) col = m;
						sum+=sumc[n][col]-sumc[i-1][col];
						sum+=sumc[j-n][col]-sumc[0][col];
						ans=max(ans,sum);
						if(sum<0) sum=0;
					}
				}
			}
			else{
				for(int k=1;k<=m;k++){ 
					ll sum=0;
					for(int l = 0;l < m;l++){
						int col = (l+k)%m;
						if(col==0) col = m;
						sum+=sumc[j][col]-sumc[i-1][col];   
						ans=max(ans,sum);
						if(sum<0) sum=0;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

