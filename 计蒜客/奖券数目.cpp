#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int ans=0;
	for(int i=1e4;i<1e5;i++)
	{
		bool flag=true;
		int temp=i;
		while(temp)
		{
			if(temp%10==4)
			{
				flag=false;
				break;
			}
			temp/=10;
		}
		if(flag)
		{
			ans++;//cout<<i<<endl;
		} 
	}
	cout<<ans<<endl;
	return 0;
}
