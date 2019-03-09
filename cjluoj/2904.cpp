#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	int c, q = 1;
	while(scanf("%c",&c)!=EOF)
	{
		if(c == '"')
                {
			printf("%s",q?"``":"''" );
			q=!q;
		}
		else
			printf("%c",c);
	}
	return 0;
}
