#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
bool vis[10][10],h[10][10];
int acnt = 30,ans = 0;
int dx[8] = {-2,-2,-1,1,2,2,1,-1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};
int dxx[4] = {-1,0,1,0};
int dyy[4] = {0,1,0,-1};
bool in(int x,int y){
	return x>0&&y>0&&x<=5&&y<=5;
}
int main()
{
	int r = 1<<25;
	for(int k = 0;k < r;k++){
		int cnt = 0;
		memset(h,false,sizeof(h));
		memset(vis,false,sizeof(vis));
		for(int i = 0;i < 25;i++){
			if((k>>i)&1){
				cnt++;
				int x = (i+1)/5+1,y = (i+1)%5;
				if(y==0) x--,y = 5;
				h[x][y] = vis[x][y] = true;
			}
		}
//		cout<<"==========="<<k<<endl;
//				for(int x = 1;x <= 5;x++){
//					for(int y = 1;y <= 5;y++){
//						if(h[x][y]) printf(" x");
//						else printf("%2d",vis[x][y]);
//					}
//					puts("");
//				}
		int tot = cnt;
		if(cnt > acnt) continue;
		for(int x = 1;x <= 5;x++){
			for(int y = 1;y <= 5;y++){
				if(h[x][y]){
					for(int i = 0;i < 8;i++){
						int tx = x+dx[i];
						int ty = y+dy[i];
						if(in(tx,ty) && !vis[tx][ty] && !h[x+dxx[i/2]][y+dyy[i/2]]){
							vis[tx][ty] = true;
							tot++;
						}
					}
				}
			}
		}
		if(tot==25){			
//			cout<<"==========="<<endl;
//				for(int x = 1;x <= 5;x++){
//					for(int y = 1;y <= 5;y++){
//						if(h[x][y]) printf(" x");
//						else printf("%2d",vis[x][y]);
//					}
//					puts("");
//				}
			if(cnt<acnt){
				acnt = cnt;
				ans = 1;
			}
			else if(cnt == acnt)
			{
				ans++;
			}
		}
	}
	cout<<acnt<<' '<<ans<<endl;
	return 0;
}

