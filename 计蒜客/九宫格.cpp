#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n[9]={1,2,3,4,5,6,7,8,9};
	int ans=0;
	do
	{
		int rsum=n[0]+n[1]+n[2];
		int csum=n[0]+n[3]+n[6];
		if(n[1]+n[4]+n[7]==csum&&n[2]+n[5]+n[8]==csum
		&&n[3]+n[4]+n[5]==rsum&&n[6]+n[7]+n[8]==rsum)
		ans++;
	}while(next_permutation(n,n+9));
	cout<<ans<<endl;
	return 0;
}
