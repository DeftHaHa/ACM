#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,k;
	int a[105];
	cin>>n>>k;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int ans=0;
	for(int i=0;i<n;i++)
	{  //for(int k=0;k<n;k++) cout<<a[k]<<" ";cout<<endl;
		if(a[i]>0)
		{
			ans+=a[i];
			for(int j=i+1;j<i+k&&j<n;j++)
			{
				a[j]-=a[i];
			}
			a[i]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
