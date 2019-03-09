#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	int n;
	long long x;
	cin>>n>>x;
	int opt[105];
	long long num[105];
	for(int i = 0;i < n;i++){
		cin>>opt[i]>>num[i];
	}
	for(int i = n-1;i>=0;i--){
		if(opt[i] == 1) x = x - num[i];
		else if(opt[i] == 2) x = x + num[i];
		else if(opt[i] == 3) x = x/ num[i];
		else x = x*num[i];
	}
	cout<<x<<endl;
    return 0;
}
