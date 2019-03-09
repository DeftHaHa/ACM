#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,pos[100005],N;
int main()
{
	scanf("%d",&N);
	int ans = 0;
	for(int i = 0;i < N;i++){
		scanf("%d",&a);
		pos[a] = i;
	}
	for(int i = 0;i < N;i++){
		while(pos[0] != 0){
			swap(pos[0],pos[pos[0]]);
			ans++;
		}
		if(pos[i] != i){
			swap(pos[i],pos[0]);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
