#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a[105];
	int N,M;
	while(cin>>N>>M)
	{
		for(int i=0;i<N;i++)
			cin>>a[i];
		M%=N;
		cout<<a[(N-M)%N];
		for(int i=N-M+1;i<2*N-M;i++)
			cout<<' '<<a[i%N];
	}
	return 0;
}