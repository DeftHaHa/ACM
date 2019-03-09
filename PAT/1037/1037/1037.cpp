#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
bool cmp(const long long &a,const long long &b)
{
	return a>b;
}
long long c[100005],p[100005];
int main()
{
	int NC,NP;
	cin>>NC;
	for(int i=0;i<NC;i++) scanf("%lld",&c[i]);
	cin>>NP;
	for(int i=0;i<NP;i++) scanf("%lld",&p[i]);
	sort(c,c+NC,cmp);
	sort(p,p+NP,cmp);
	long long ans=0;
	for(int i=0;i<NC&&i<NP;i++)
	{
		if(c[i]<0||p[i]<0) break;
		ans+=c[i]*p[i];
	}
	for(int i=NC,j=NP;i>=0&&j>=0;i--,j--)
	{
		if(c[i]>0||p[i]>0) break;
		ans+=c[i]*p[j];
	}
	cout<<ans<<endl;
	return 0;
}