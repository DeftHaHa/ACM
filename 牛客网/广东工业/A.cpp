#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cout<<(1<<(n-1))<<endl;
	}
	return 0;
}
