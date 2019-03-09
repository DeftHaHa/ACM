#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int num[10]={0,1,2,3,4,5,6,7,8,9};
	int ca[10];
	for(int i=0;i<10;i++) ca[i]=i*i*i*i;
	do
	{
		if(num[0])
		{
			if(ca[num[0]]+ca[num[1]]+ca[num[2]]+ca[num[3]]==
			num[0]*1000+num[1]*100+num[2]*10+num[3])
			printf("%d%d%d%d\n",num[0],num[1],num[2],num[3]);
		}
	}while(next_permutation(num,num+10));
	return 0;
}
