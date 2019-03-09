#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
using namespace std;
char s[1005];
int len;
int pathx[1005],pathy[1005];
bool Map[4][4];
bool Find = false;
void dfs(int deep){
	if(Find) return;
	if(deep >= len){
		Find = true;
		return;
	}
	int clr = -1,clr2 = -1,clc = -1,clc2 = -1;
	bool flag = false;
	if(s[deep] == '0'){
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 4;j++){
				if(!Map[i][j] && !Map[i+1][j]){
					//cout<<i<<'#'<<j<<endl;
					flag = true;
					Map[i][j] = Map[i+1][j] = true;
					pathx[deep] = i+1;
					pathy[deep] = j+1;
					clr = i,clr2 = i+1,clc = j;
					for(int i = 0;i < 4;i++){
						if(!Map[i][clc]) clc = -1;
						if(!Map[clr2][i]) clr2 = -1;
						if(!Map[clr][i]) clr = -1;
					}
					break;
				}
			}
			if(flag) break;
		}
	}
	else{
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 3;j++){
				if(!Map[i][j] && !Map[i][j+1]){
					flag = true;
					pathx[deep] = i+1;
					pathy[deep] = j+1;
					Map[i][j] = Map[i][j+1] = true;
					clr = i,clc = j,clc2 = j+1;
					for(int i = 0;i < 4;i++){
						if(!Map[i][clc]) clc = -1;
						if(!Map[clr][i]) clr = -1;
						if(!Map[i][clc2]) clc2 = -1;
					}
					break;
				}
			}
			if(flag) break;
		}
	}
	if(flag){
		for(int i = 0;i < 4;i++){
			Map[i][clc] = clc == -1 ? Map[i][clc] : false; 
			Map[i][clc2] = clc2 == -1 ? Map[i][clc2] : false; 
			Map[clr][i] = clr == -1 ? Map[clr][i] : false; 
			Map[clr2][i] = clr2 == -1 ? Map[clr2][i] : false; 
		}
//		for(int i = 0;i < 4;i++)
//		{
//			for(int j = 0;j < 4;j++){
//				printf("%2d",Map[i][j]);
//			}cout<<endl;
//		}
		dfs(deep+1);
		for(int i = 0;i < 4;i++){
			Map[i][clc] = clc == -1 ? Map[i][clc] : true; 
			Map[i][clc2] = clc2 == -1 ? Map[i][clc2] : true; 
			Map[clr][i] = clr == -1 ? Map[clr][i] : true; 
			Map[clr2][i] = clr2 == -1 ? Map[clr2][i] : true; 
		}
	}
	else return;
}
int main()
{
	
	scanf("%s",s);
	len = strlen(s);
	memset(Map,false,sizeof(Map));
	dfs(0);
	for(int i = 0;i < len;i++){
		printf("%d %d\n",pathx[i],pathy[i]);
	}
	return 0;
}
