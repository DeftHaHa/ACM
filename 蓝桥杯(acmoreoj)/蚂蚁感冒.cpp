#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	int x[55];
	cin>>n;
	int s;
	cin>>s;
	for(int i=1;i<n;i++) scanf("%d",&x[i]);
	bool flagr=false,flagl=false;
	int ans=1;
	for(int i=1;i<n;i++)
	{
		if(x[i]>0&&abs(x[i]) < abs(s))
		{
			flagl=true;
			ans++;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(x[i]<0&&abs(x[i]) >abs(s))
		{
			ans++;
			flagr=true;	
		}
	}
	if((s<0&&flagl)||(s>0&&flagr)) cout<<ans<<endl;
	else cout<<1<<endl;
	return 0;
}
