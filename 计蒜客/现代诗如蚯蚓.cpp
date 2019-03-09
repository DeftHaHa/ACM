#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int Next[1005];
	char s[1005];
	scanf("%s",s);
	int l=strlen(s);
	Next[0]=-1;
	int k=-1;
	for(int i=1;i<l;i++)
	{
		while(k>-1&&s[k+1]!=s[i]) k=Next[k];
		if(s[k+1]==s[i]) k++;
		Next[i]=k;
	}
	printf("%d\n",l/(l-1-Next[l-1]));
	return 0;
}
