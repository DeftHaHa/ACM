#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
	int N1,N2;
	float m[1005];
	for(int i=0;i<=1000;i++) m[i]=0;
	while(cin>>N1)
	{
		int a;
		float b;
		while(N1--)
		{
			cin>>a>>b;
			m[a]+=b;
		}
		cin>>N2;
		while(N2--)
		{
			cin>>a>>b;
			m[a]+=b;
		}
		int cnt=0;
		for(int i=0;i<=1000;i++)
		{
			if(m[i]!=0) cnt++;
		}
		cout<<cnt;
		for(int i=1000;i>=0;i--)
		{
			if(m[i]!=0)
				printf(" %d %.1f",i,m[i]);
		}
		cout<<endl;
		for(int i=0;i<=1000;i++) m[i]=0;
	}
	return 0;
}