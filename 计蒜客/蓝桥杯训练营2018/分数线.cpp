#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int mid = n/2 + 1;
	int ans1 = a[mid];
	while(mid-1>=1&&a[mid-1]==ans1)
	{
		mid--;  
	}
	cout<<ans1<<' '<<n-mid+1<<endl;
	return 0;
}
