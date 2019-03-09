#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int ans = 0x3f3f3f3f;
	for(int i = 1;i <= n;i++)
	{
		if(n%i==0)
		{
			int l = ceil((double)((double)n*k/i-i)/(double)k);
			int r = (int)(((double)n*k/i+k-1-i)/k);
			int t = l*k+i;
			if(r>=l &&((t/k)*(t%k) == n)) ans = min(ans,t);
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
