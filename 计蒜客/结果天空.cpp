#include<iostream>
#include<cstring>
#include<cstring>
using namespace std;
int main()
{
	long long ans=0;
	for(int i=2;i<=10000;i++)
	{
		int sum=1;
		for(int j=2;j<i;j++)
		{ 
			if(i%j==0)
			{
				sum+=j;
				if(sum>i) break;
			}
		}
		if(sum==i) ans+=i;
	}
	cout<<ans<<endl;
	return 0;
}
