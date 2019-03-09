#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
int b[100005];
int main(){
	
	int D,N;
	scanf("%d%d",&D,&N);
	int len = 1;
	a[0] = D;
	for(int i = 0;i < N - 1;i++)
	{
		int num = a[0],tot = 1;
		int tlen = 0;
		for(int j = 1;j < len;j++){
			if(num==a[j]) tot++;
			else{
				b[tlen++] = num; 
				b[tlen++] = tot;
				num = a[j]; 
				tot = 1;
			}
		}
		b[tlen++] = num;
		b[tlen++] = tot;
		len = tlen;
		for(int j = 0;j < len;j++) a[j] = b[j];
	}
	for(int i = 0 ; i < len;i++){
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
