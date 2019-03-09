#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int temp=5;
	int ans=0;
	for(int i=2000;i<=2100;i++)
	{
		int day=365;
		if(i%400==0||(i%4==0&&i%100!=0)) day++;
		temp=temp+day%7;
		temp%=7;
		if(temp==6) ans++;
	}cout<<ans<<endl;
	return 0;
}
