#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	for(int i=10;i<100;i++)
	{
		int temp=(i%10)*10+i/10;
		int x=i+temp;
		int y=abs(i-temp);
		if(x-y==32) cout<<y<<endl;
	}
	return 0;
}
