#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int x[505],y[505];
bool vis[605][605];
int main()
{
	int N;
	while(~scanf("%d",&N)){
		memset(vis,false,sizeof(vis));
		for(int i = 1;i <= N;i++){
			scanf("%d%d",&x[i],&y[i]);
			x[i]+=300;
			y[i]+=300;
			vis[x[i]][y[i]] = true;
		}
		int ans = 0;
		for(int i = 1;i <= N;i++){
			for(int j = i+1;j <= N;j++){
				int dx = x[i]-x[j],dy = y[i]-y[j];   
				if(vis[x[i]+dy][y[i]-dx]&&vis[x[j]+dy][y[j]-dx]) ans++;
				if(vis[x[i]-dy][y[i]+dx]&&vis[x[j]-dy][y[j]+dx]) ans++;
			}
		}
		printf("%d\n",ans/4);
	}
	return 0;
}
