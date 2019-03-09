#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
double d[1005][1005];
double x[1005],y[1005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				d[j][i]=d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					if(k!=i&&k!=j&&d[i][j]==d[j][k]) ans++;
				}
			}
		}
		if(ans) printf("%d\n",ans);
		else printf("WA\n");
	}
	return 0;
}
