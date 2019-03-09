#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int sx,sy,ex,ey;
int n;
char s[100005];
int dx[100005],dy[100005];
int main()
{
	scanf("%d%d%d%d%d",&sx,&sy,&ex,&ey,&n);
	scanf("%s",s);
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy));
	for(int i = 0;i < n;i++){
		if(s[i]=='U') dy[i+1] = dy[i] + 1;
		else if(s[i]=='D') dy[i+1] = dy[i] - 1;
		else if(s[i]=='L') dx[i+1] = dx[i] - 1;
		else dx[i+1] = dx[i] + 1;
	}
	int d1 = dx[n],d2 = dy[n];
	int c1 = ex - sx;
	int c2 = ey - sy;
	int ans = 2e9;
	for(int i = 1;i <= n;i++){
		// > >
		int c = c1+c2,a = d1+d2;
		
		
	}
	return 0;
}
