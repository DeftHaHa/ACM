#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int n[14]={85,13,75,80,65,34,8,44,73,67,77,90,29,14};
	int ans=0;
	do
	{
		bool flag=true;
		if(gcd(n[0],n[13])!=1) flag=false;
		else
		{
			for(int i=1;i<5;i++)
			{
				if(gcd(n[i],n[i-1])!=1)
				{
					flag=false;
					break;
				}
			}
		}
		if(flag) { ans++;
		}
		
	}while(next_permutation(n,n+14));
	cout<<ans<<endl;
	cout<<ans/5/4<<endl;
	return 0;
}
