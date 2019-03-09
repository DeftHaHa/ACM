#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
int main()
{
	double sum = 0;
	for(int i = 1;;i++){
		
		sum += log10(i);
	//	cout<<i<<' '<<(int)sum+1<<endl;
		if((int)sum+1 >=10000){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
