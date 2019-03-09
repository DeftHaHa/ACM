#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int x,y,z,g,p,b;
	scanf("%d%d%d%d%d%d",&x,&y,&z,&g,&p,&b);
	bool ok = true;
	if(g < x) ok = false;
	if(p+g-x < y) ok = false;
	if(g+p+b-x-y < z) ok = false;
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}
