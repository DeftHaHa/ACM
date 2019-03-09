#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	int l1,l2,r1,r2;
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int p1 = l1,p2 = l2;
		if(p1==p2) {
			if(l1!=r1) p1++;
			else p2++;
		} 
		
		printf("%d %d\n",p1,p2);
	}
	return 0;
}
