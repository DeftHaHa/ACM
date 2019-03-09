#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxl=100005;
char s[maxl],tmp[maxl];
int main()
{
	memset(s,0,sizeof(s));
	while(~scanf("%s",s))
	{
		int l=strlen(s);
		char max=0;
		for(int i=l-1;i>=0;i--)
		{
			if(s[i]>max)
			{
				max=s[i];
				tmp[i]=s[i];
			}
			else tmp[i]=max;
		}
		for(int i=0;i<l;i++)
		{
			if(s[i]>=tmp[i]) printf("%c",s[i]);
		}
		printf("\n");
		memset(s,0,sizeof(s));
	}
	return 0;
}

