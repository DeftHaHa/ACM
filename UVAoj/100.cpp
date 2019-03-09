#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len[1000005];
int main()
{
	memset(len,0,sizeof(len));
	long long i,j;
	len[1] = 1;
	while(cin>>i>>j)
	{
		long long s=i,e=j;
		if(s>e) swap(s,e);
		int ans = 0;
		for(int i = s;i <= e;i++)
		{
			int cnt = 0;
			long long n = (long long)i;
			while(1)
			{
				if(n<=1000000&&len[n])
				{
					cnt += len[n];
					break;
				}
				if(n&1) n = n*3+1;
				else n/=2;
				cnt++;
			}
			len[i] = cnt;
			ans = max(ans,len[i]);
		}
		cout<<i<<' '<<j<<' '<<ans<<endl;
	}
	
	return 0;
}
