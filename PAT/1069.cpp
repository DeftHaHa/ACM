#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int n;
	int a[5],b[5];
	scanf("%d",&n);
	while(1){
		int t = n,len = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		while(t){
			a[len] = b[len] = t%10; 
			len++;
			t/=10;
		}
		sort(a,a+4,cmp);
		sort(b,b+4); 
		int A = 0,B = 0;
		for(int i = 0;i < 4;i++){
			A = A * 10 + a[i];
			B = B * 10 + b[i];
		}
		printf("%04d - %04d = %04d\n",A,B,A-B);
		n = A - B;
		if(n==0 || n == 6174) break;
	}
	return 0;
	
} 
