#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			ans+=i*i*i;
		printf("%d\n",ans);
	}
	return 0;
}