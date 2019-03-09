#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int N;
	while(cin>>N)
	{
		int a[105];
		a[0]=0;
		for(int i=1;i<=N;i++)
			cin>>a[i];
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(a[i+1]>a[i])
				ans+=6*(a[i+1]-a[i]);
			else ans+=4*(a[i]-a[i+1]);
		}
		ans+=N*5;
		cout<<ans<<endl;
	}
	return 0;
}