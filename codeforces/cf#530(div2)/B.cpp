#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a = sqrt(n);
	int b = n/a;
	if(a*b < n) b++;
	cout<<a+b<<endl;
	return 0;
}
