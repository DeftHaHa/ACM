#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int N;
	int t[105];
	cin>>N;
	for(int i = 1 ; i <= N;i++) scanf("%d",&t[i]);
	int w1,w2;
	int temp[105];
	for(int i = 1 ;i <= N;i++){
		for(int j = i+1;j <= N;j++){
			memset(temp,0,sizeof(temp));
			bool conf = false;
			int wlcnt = 0,hlcnt = 0;
			for(int k=1;k <= N;k++){
				int tag = abs(t[k]);
				int is_h = t[k] > 0 ? 1 : -1;
				if(k==i || k==j){
					if(tag!=i && tag!=j && is_h < 0) wlcnt++;
					else if((tag==i || tag==j)&& is_h > 0) wlcnt++;
				}
				else{
					if(tag!=i && tag!=j && is_h < 0) hlcnt++;
					else if((tag==i || tag==j)&& is_h > 0) hlcnt++;
				}
			}
			if(hlcnt==1 && wlcnt==1){
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}
