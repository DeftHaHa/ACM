#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1000005];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	sort(a,a+N);
	int tag=N+1;
	for(int i=0;i<N;i++) 
	{
		if(a[i]>0)
		{
			tag=i;
			break;
		}
	}
	int ans=1;
	for(int i=tag;i<N;i++)
	{ //cout<<a[i]<<" "<<ans<<endl;
		if(a[i]==a[i-1]) continue;
		if(a[i]!=ans) break;
		ans++;
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}