#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int Min = 0x3f3f3f3f,ans;
	int sum;
	int a[105];
	for(int i = 1; i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++)
	{
		sum = 0;
		for(int j = 1;j <= n;j++)
		{
			sum += a[j]*(abs(i-j) + j + i - 2)*2;
		}
		if(sum < Min)
		{
			Min = sum;
		}
	}
	cout<<Min<<endl;
	return 0;
}
