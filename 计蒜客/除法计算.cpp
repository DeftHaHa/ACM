#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long n;
int Try(int x)
{
	long long res=1;
	int cnt;
	while(res<n)
	{
		res*=x;
		x++;
	}
	if(res==n) return x;
	else return -1;
}
int main()
{
	cin>>n;
	bool flag=false;
	if(n==1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++)
	{
		if(Try(i)!=-1)
		{
			flag=true;
			cout<<Try(i)-1<<' '<<i-1<<endl;
			break;
		}
	}
	if(!flag) cout<<n<<' '<<n-1<<endl;
	return 0;
}
