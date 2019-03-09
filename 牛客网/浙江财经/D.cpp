#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int T,c=0;
	cin>>T;
	while(T--)
	{
		int L,X,R;
		scanf("%d%d%d",&L,&R,&X);
		int a=X-L;
		int b=R-X;
		printf("Case #%d: ",++c);
		if(a==b) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
} 
