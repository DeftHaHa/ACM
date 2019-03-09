#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int N;
	while(T--)
	{
		cin>>N;
		if(N%7==0) cout<<N/7<<endl;
		else cout<<N/7+1<<endl;
	}
	return 0;
}
