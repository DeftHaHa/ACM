#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c;
		int p,q,r,s;
		scanf("%d%d%d%d%d%d%d",&a,&b,&c,&p,&q,&r,&s);
		int ans=a*(q-p+s-r)+2*c*b+min((r-q)*a,2*c*b);
		cout<<ans<<endl;
	}
	return 0;
}