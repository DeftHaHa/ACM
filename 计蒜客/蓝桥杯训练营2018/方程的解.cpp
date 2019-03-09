#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int l = sqrt(n);
	for(int a = 1;a <= l;a++){
		for(int b = a+1;b <= l;b++){
			for(int c = b+1;c <= l;c++){
				if(a*a + b*b + c*c == n){
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
	return 0;
}
