#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	char s[20005],temp[5005];
	scanf("%s",temp);
	s[0]='+';
	s[1]='#';
	int cnt=1;
	for(int i=0;i<strlen(temp);i++)
	{
		s[++cnt]=temp[i];
		s[++cnt]='#';
	}
	s[++cnt]='-';
	int pos,maxr=-1;
	int pal[20005];
	int ans=0;
	for(int i=1;i<cnt;i++)
	{
		if(i>maxr) pal[i]=1;
		else pal[i]=min(pal[2*pos-i],maxr-i+1);
		while(s[i-pal[i]]==s[i+pal[i]]) pal[i]++;
		if(i+pal[i]-1>maxr)
		{
			maxr=i+pal[i]-1;
			pos=i;
			ans=max(ans,pal[i]-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
