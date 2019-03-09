#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
using namespace std;
long long a,x,mod;
long long quickpow(long long a,int n)
{
	long long res=1;
	while(n)
	{
		if(n&1) res*=a;
		a=(a*a)%mod;
		n>>=1;
	}
	return res%mod;
}
struct cmp
{
	bool operator()(const long long &a,const long long &b)
	{
		return a>b;
	}
};
priority_queue<long long,vector<long long>,cmp> q;
int main()
{
	int n,k;
	cin>>n>>k;
	cin>>a>>x>>mod;
	q.push(a);
	for(int i=1;i<n;i++)
	{
		q.push(quickpow(a,i));
	}
	k--;
	while(k--) q.pop();
	cout<<q.top()<<endl;
}
