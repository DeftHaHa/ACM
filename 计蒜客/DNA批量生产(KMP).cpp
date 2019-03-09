#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[200005],ptr[200005];
int NEXT[200005];
int main()
{
	memset(str,0,sizeof(str));
	memset(ptr,0,sizeof(ptr));
	scanf("%s",str);
	scanf("%s",ptr);
	NEXT[0]=-1;
	int k=-1;
	int l=strlen(ptr);
	int ans=0;
	for(int i=1;i<l;i++)
	{
		while(k>-1&&ptr[k+1]!=ptr[i])
		{
			k=NEXT[k];
		}
		if(ptr[k+1]==ptr[i]) k++;
		NEXT[i]=k;     cout<<i<<' '<<NEXT[i]<<endl;
	}
	k=-1;
	for(int i=0;i<strlen(str);i++)
	{
		while(k>-1&&ptr[k+1]!=str[i])
		{
			k=NEXT[k];
		}
		if(ptr[k+1]==str[i]) k++;
		if(k==l-1)
		{
			k=-1;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
