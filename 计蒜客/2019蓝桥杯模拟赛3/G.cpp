#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> mat[100005];
int main()
{
	int n,m,op,x;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		mat[i] = vector<int>(m+1);
		mat[i].push_back(0);
		for(int j = 1;j <= m;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	scanf("%d",&op);
	int y,z;
	while(op--){
		scanf("%d%d%d",&x,&y,&z);
		if(x) for(int i = 1;i <= n;i++) swap(mat[i][y],mat[i][z]);
		else for(int i = 1;i <= m;i++) swap(mat[y][i],mat[z][i]);
	}
	for(int i = 1;i <= n;i++){
		printf("%d",mat[i][1]);
		for(int j = 2;j <= m;j++) printf(" %d",mat[i][j]);
		puts("");
	}
	return 0;
}
