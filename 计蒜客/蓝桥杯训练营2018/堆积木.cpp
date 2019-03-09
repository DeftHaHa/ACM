#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int> v[10005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i = 1;i <= n;i++) v[i].push_back(i);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		int len = v[b].size();
		if(a!=b){
			for(int i = 0;i < len;i++) {
				v[a].push_back(v[b][i]);
			}
			vector<int>x;
			x.swap(v[b]);
		}
		
	}
	for(int i = 1;i <= n;i++){
		int len = v[i].size();
		if(len) printf("%d",v[i][0]);
		for(int j = 1; j < len;j++) printf(" %d",v[i][j]);
		printf("\n");
	}
	return 0;
}
