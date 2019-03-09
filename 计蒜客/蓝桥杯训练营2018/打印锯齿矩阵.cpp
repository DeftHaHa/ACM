#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> a[10005];
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}
	for(int i = 1;i <= n;i++){
		int len = a[i].size();
		for(int j = 0;j < len;j++){
			printf("%d",a[i][j]);
			if(j<len-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
