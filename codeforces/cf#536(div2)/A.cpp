#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,-1,1};
char Map[505][505];
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			scanf("%c",&Map[i][j]);
		}
		getchar();
	}
	int ans = 0;
	for(int i = 1;i < n-1;i++){
		for(int j = 1;j < n-1;j++){
			if(Map[i][j] == 'X'){
				bool ok = true;
				for(int k = 0;k < 4;k++){
					if(Map[i+dx[k]][j+dy[k]]!='X'){
						ok = false;
						break;
					} 
				}
				if(ok) ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
