#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool prime(int n)
{
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int N,D;
	while(cin>>N)
	{
		if(N<0) break;
		cin>>D;
		int tot=0,sum=0,temp=N,num[105];
		while(temp>0)
		{
			num[tot++]=temp%D;
			temp/=D;
		}
		int j=0;
		for(int i=tot-1;i>=0;i--) sum+=num[i]*pow(D,j++);
		if(prime(N)&&prime(sum)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}