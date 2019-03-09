#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	
	int h1,h2,m1,m2;
	scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
	int d = h2*60 + m2 + h1 * 60 + m1;
	printf("%02d:%02d\n",d/2/60,d/2%60);
	
	return 0;
}
