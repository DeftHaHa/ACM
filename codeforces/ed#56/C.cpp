#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
long long a[200005];
int main()
{
	int n;
	cin>>n;
	long long b;
	scanf("%I64d",&b);
	a[1] = 0;
	a[n] = b;
	for(int i = 2;i <= n/2;i++)
	{
		scanf("%I64d",&b);
		if(b - a[i-1] <= a[n-i+2])
		{
			a[i] = a[i-1];
			a[n-i+1] = b - a[i-1];
		}
		else if(b - a[n-i+2] >= a[i-1])
		{
			a[n-i+1] = a[n-i+2];
			a[i] = b - a[n-i+1]; 
		}
	}
	printf("%I64d",a[1]);
	for(int i = 2;i <=n ;i++) 
	{
		printf(" %I64d",a[i]);
	}
	cout<<endl;
	return 0;
}
