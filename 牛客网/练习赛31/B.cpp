#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		if(n==1) cout<<"Kozilek, Butcher of Truth"<<endl;
		else if(n==3) cout<<"Ulamog, the Infinite Gyre"<<endl;
		else if(n&1) cout<<"Kozilek, Butcher of Truth"<<endl;
		else cout<<"Ulamog, the Infinite Gyre"<<endl;
	}
	return 0;
}
