#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	char ch=getchar();
	char s[2000];
	while(T--)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);
		ch=getchar();
		int l=strlen(s);
		int tag;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='.')
			{
				tag=i;
				break;
			}
		}
		if(tag>=l) tag=l-1;
		bool flag=false;
		for(int i=l-1;i>tag;i--)
		{
			if(s[i]-'0'>=5) flag=true;
			else if(flag&&s[i]-'0'>=4) flag=true;
			else flag=false;
		}
		unsigned long long ans=0;
		for(int i=0;i<tag;i++)
		{
			ans=ans*10+(long long)(s[i]-'0');
		}
		if(flag) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
