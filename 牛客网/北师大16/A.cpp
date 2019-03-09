#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[10];
int main()
{
	int T,n;
	cin>>T;
	while(~scanf("%d",&n))
	{
		bool flag=true;
		while(n--)
		{
			scanf("%s",s);
			if(s[0]!='P') flag=false;
		}
		if(flag) printf("MILLION Master\n");
		else printf("NAIVE Noob\n");
	}
	return 0;
}
