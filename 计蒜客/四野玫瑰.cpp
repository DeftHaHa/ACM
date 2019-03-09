#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	for(int i=1e3;i<1e4;i++)
	{
		int num=i,sum=0;
		while(num)
		{
			int x=num%10;
			sum+=x*x*x*x;
			num/=10;
		}//cout<<i<<' '<<sum<<endl;
		if(sum==i) printf("%d ",i);
	}
	return 0;
}
