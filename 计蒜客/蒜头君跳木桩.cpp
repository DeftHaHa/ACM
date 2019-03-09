#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int len=1,ans[100005];
	int h[100005];
	for(int i=0;i<n;i++) scanf("%d",&h[i]);
	ans[0]=h[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(h[i]>=ans[len-1])
		{
			ans[len++]=h[i];
		}
		else
		{
			int pos=lower_bound(ans,ans+len,h[i])-ans;
			ans[pos]=h[i];
		}
	}
	cout<<len<<endl;
	return 0;
}
