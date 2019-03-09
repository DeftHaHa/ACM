#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	char s[105];
	scanf("%d%d",&n,&m);
	int ans=0;
	while(n--)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);
		int l=strlen(s);
		if(l-4<=m&&s[l-1]=='m'&&s[l-2]=='o'&&s[l-3]=='c'&&s[l-4]=='.') ans++;
	}
	printf("%d\n",ans);
	return 0;
}