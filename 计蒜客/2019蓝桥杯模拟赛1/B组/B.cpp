#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int h = 60405,u = 105,d = 35;
	int sum = 0,day = 1;
	cout<<60405/70+1<<endl;
	while(1){
		sum += u;
		cout<<day<<'='<<sum<<endl;
		if(sum >= h){
			cout<<sum <<"##"<<day<<endl;
			break;
		}
		sum -= d; 
		day++;
	}
	return 0;
}
