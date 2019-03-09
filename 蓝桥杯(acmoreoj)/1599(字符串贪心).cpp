#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s1[1005],s2[1005];
bool S1[1005],S2[1005];

int main()
{
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	scanf("%s",s1);
	scanf("%s",s2);
	int len=strlen(s1);
	for(int i=0;i<len;i++)
	{
		if(s1[i]=='*') S1[i]=true;
		else S1[i]=false;
		if(s2[i]=='*') S2[i]=true;
		else S2[i]=false;
	}  
	int ans=0;
	for(int i=0;i<len-1;i++)
	{
		if(S1[i]!=S2[i])
		{
			ans++;
			S1[i+1]=!S1[i+1];
		}
	}
	cout<<ans<<endl;
	return 0;
}
