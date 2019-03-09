#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n[11]={0,1,2,3,4,5,6,7,8,9};
	int ans=0;
	do
	{
		if(n[0]&&n[2]&&n[5])
		{
			if((n[0]*10+n[1])*(n[2]*100+n[3]*10+n[4])==
			n[5]*10000+n[6]*1000+n[7]*100+n[8]*10+n[9])
			{
				printf("%d%d\nX\t%d%d%d\n%d%d%d%d%d\n",
				n[0],n[1],n[2],n[3],n[4],n[5],n[6],n[7],n[8],n[9]);
				ans++;
			}
		}
	}while(next_permutation(n,n+10));
	cout<<ans<<endl;
	return 0;
}
