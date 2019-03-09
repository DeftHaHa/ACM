#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	double sum = 0;
	for(double i = 1;i <= 2019;i++){
		sum += 1/i;
	}
	printf("%.4lf",sum);
	return 0;
}
