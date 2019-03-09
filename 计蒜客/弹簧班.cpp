#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a[100005],step[100005];
	memset(step,0,sizeof(step));
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(a[i]+i>n) step[i]=1;
		else step[i]=step[i+a[i]]+1;
		ans=max(ans,step[i]);
	}
	cout<<ans<<endl;
	return 0;
}
