#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		if(n&1&&m&1) cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
	}

	return 0;
}