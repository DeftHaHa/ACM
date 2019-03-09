#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a;
	vector<long long> v;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		v.push_back(a);
	}
	int ans=0;
	for(int i=1;i<v.size();)
	{      /*cout<<v[i-1]<<' '<<v[i]<<' '<<v.size()<<':';for(int j=0;j<v.size();j++)
			{
				cout<<' '<<v[j];
			}cout<<endl;*/
		if(v[i]-v[i-1]==1)
		{
			v.erase(v.begin()+i);
			ans++;
		}
		else if(v[i-1]-v[i]==1)
		{
			v.erase(v.begin()+(i-1));
			ans++;
		}
		else i++;
	}
	cout<<ans<<endl;
	return 0;
}
