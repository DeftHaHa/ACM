#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	for(int i=1;i<=200;i++)
	{
		int sum=0;
		for(int j=i;j<=200;j++)
		{
			sum+=j;
			if(sum==236)
			{
				printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}
