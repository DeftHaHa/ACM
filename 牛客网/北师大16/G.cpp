#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[25];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);
		int cnt=1;
		int len=strlen(s);
		if(s[1]<='A'&&s[1]>='a')
		{
			printf("%c",s[0]+32);
		
		}
		else printf("%c",s[0]);
		for(int i=1;i<len;i++)
		{
		
			if(s[i]<='Z')
			{
				if(cnt>=2&&i+2<len&&s[i+1]>='a')
				{
					printf("_");
					printf("%c",s[i]+32);
				}
				else printf("%c",s[i]);
				cnt=1;
			}
			else
			{
				cnt++;
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}





