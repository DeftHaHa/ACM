#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,num;
	while(~scanf("%d%d",&n,&x)){
		if(!n && !x) return 0;
		bool flag = true;
		for(int i = 0;i < n;i++){
			scanf("%d",&num);
			if(num>x && flag){
				printf("%d ",x);
				flag = false;
			}
			printf("%d",num);
			if(flag || i!=n-1) printf(" ");
		}
		if(flag) printf("%d\n",x);
		else printf("\n");
	}
	return 0;
}
