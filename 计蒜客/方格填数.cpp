#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int num[10]={0,1,2,3,4,5,6,7,8,9};
	int ans=0;
	do
	{
		int sum=num[0]+num[1]+num[2]+num[3];
		if(num[2]+num[3]+num[4]+num[5]==sum&&
		num[4]+num[5]+num[6]+num[7]==sum&&
		num[6]+num[7]+num[8]+num[9]==sum)
		{
			ans++;
		}
		
	}while(next_permutation(num,num+10));
	cout<<ans<<endl;
}
