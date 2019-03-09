#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const long long mod1 = 1e9+7;
const long long mod2 = 19970809;
map<pair<long long,long long>,int> Map;
bool pre[100005];
long long w1[100005],w2[100005];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		Map.clear();
		memset(pre,true,sizeof(pre));
		w1[1] = w2[1] = 1;
		long long k1 = 0;
		long long k2 = 0;
		for(int i = 2;i <= 100000;i++)
		{
			w1[i] = w1[i-1]*2%mod1;
			w2[i] = w2[i-1]*2%mod2;
			k1 = (k1+w1[i])%mod1;
			k2 = (k2+w2[i])%mod2;
		}
		long long x;
		int ans = 0;
		while(m--)
		{
			scanf("%d",&x);
			if(pre[x])
			{
				pre[x] = false;
				k1 = (k1-w1[x]+mod1)%mod1;  //注意加mod防止小于零 
				k2 = (k2-w2[x]+mod2)%mod2;
			}
			else
			{
				pre[x] = true;
				k1 = (k1+w1[x])%mod1;
				k2 = (k2+w2[x])%mod2;
			}
			if(!Map[make_pair(k1,k2)])
			{
				Map[make_pair(k1,k2)] = 1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
