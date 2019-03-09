#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int M,N;
	map<long long,int> m;
	cin>>M>>N;
	int temp=M*N/2;
	long long s,ans;
	bool flag=true;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%lld",&s); 
			m[s]++;
		}
	}
	for(map<long long,int>::iterator it=m.begin();it!=m.end();it++)
	{
		if(it->second >=temp) 
		{
			ans=it->first;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}