#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n[4005];
	int p;
	cin>>p;
	char ch=getchar();
	for(int i=0;i<p;i++) {scanf("HT%d",&n[i]);char ch=getchar();}
	int ans=1,temp=n[0],tot=1;
	for(int i=1;i<p;i++)
	{
		if(n[i]=temp+1)
		{
			tot++;
		}
		else
		{
			ans=max(ans,tot);
			tot=1;
		}
		temp=n[i];
	}
	printf("%d\n",ans*100);
	return 0;
}