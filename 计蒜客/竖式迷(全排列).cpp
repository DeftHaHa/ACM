#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int num[10]={0,1,2,3,4,5,6,7,8,9};
	do
	{
		if(num[0]&&num[4])
		{
			if(num[0]*1000+num[1]*100+num[2]*10+num[3]+num[4]*100+num[5]*10+num[6]==
			num[4]*1000+num[6]*100+num[0]*10+num[1])
			{
				printf("%d%d%d%d\n+%d%d%d\n--------\n%d%d%d%d\n\n",num[0],num[1],num[2],num[3],
				num[4],num[5],num[6],num[4],num[6],num[0],num[1]);
			}
		}
	}while(next_permutation(num,num+10));
	return 0;
}
