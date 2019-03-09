#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	float w[3],t[3],l[3];
	while(cin>>w[0]>>t[0]>>l[0])
	{
		for(int i=1;i<3;i++) cin>>w[i]>>t[i]>>l[i];
		float ans=1.0;
		
		for(int i=0;i<3;i++)
		{
			float maxp=0.0;
			maxp=max(maxp,w[i]);
			maxp=max(maxp,t[i]);
			maxp=max(maxp,l[i]);
			ans*=maxp;
			if(maxp==w[i])
			{
				cout<<'W'<<' ';
				continue;
			}
			else if(maxp==t[i])
			{
				cout<<'T'<<' ';
				continue;
			}
			else if(maxp==l[i])
			{
				cout<<'L'<<' ';
				continue;
			}
		}
		printf("%.2f\n",(ans*0.65-1)*2);
	}
	return 0;
}