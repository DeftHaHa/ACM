#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int n,m,k;
	int p[105],s[105],Max[105];
	int id;
	scanf("%d%d%d",&n,&m,&k);
	memset(Max,0xc0,sizeof(Max));
	for(int i = 1;i <= n;i++) scanf("%d",&p[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&s[i]),Max[s[i]] = max(Max[s[i]],p[i]);
	int ans = 0,pos;
	for(int i = 1;i <= k;i++){
		scanf("%d",&pos);
		if(p[pos] != Max[s[pos]]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
