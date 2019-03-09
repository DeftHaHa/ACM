#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int n,a[25];
	while(T--){
		scanf("%d",&n);
		int SUM = 0;
		for(int i = 0 ;i < n;i ++){
			scanf("%d",&a[i]);
			SUM += a[i];
		}
		int w[25];
		int half = SUM / 2;
		memset(w,0,sizeof(w));
		for(int i = (1<<n)-1;i >= 0;i--){
			int sum = 0;
			for(int j = 0;j < n;j++){
				if((i>>j)&1){
					sum += a[j];
				}
			}
			if(sum > half)
				for(int j = 0;j < n;j++)
					if((i>>j)&1 && sum - a[j] <= half) w[j]++;	
		}
		printf("%d",w[0]);
		for(int i = 1;i < n;i++) printf(" %d",w[i]);
		printf("\n");
	}
	return 0;
}
