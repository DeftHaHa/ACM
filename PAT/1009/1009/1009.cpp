#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	float m1[1005],m2[1005],m[2005];
	int N1,N2;
	while(cin>>N1)
	{
		int a;
		float b;
		for(int i=0;i<=1000;i++) m1[i]=0;
		for(int i=0;i<=1000;i++) m2[i]=0;
		for(int i=0;i<=2000;i++) m[i]=0;
		while(N1--)
		{
			cin>>a>>b;
			m1[a]=b;
		}
		cin>>N2;
		while(N2--)
		{
			cin>>a>>b;
			m2[a]=b;
		}
		for(int i=0;i<=1000;i++)
		{
			if(m1[i]!=0)
			{
				for(int j=0;j<=1000;j++)
				{
					if(m2[j]!=0)
					{
						m[i+j]+=m1[i]*m2[j];
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=2000;i++) if(m[i]!=0) ans++;
		cout<<ans;
		for(int i=2000;i>=0;i--)
		{
			if(m[i]!=0)
				printf(" %d %.1f",i,m[i]);
		}
		cout<<endl;
	}
}