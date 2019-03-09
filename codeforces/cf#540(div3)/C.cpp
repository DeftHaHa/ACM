#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
int a,cnt[1005];
int mat[105][105];
int main()
{
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	for(int i = 1;i <= n*n;i++){
		scanf("%d",&a);
		cnt[a]++;
	}
	bool ok = true;
	if(n&1){
		int mid = n/2+1;
		int r1 = 1,r2 = n,c1 = 0,c2 = n+1;
		for(int i = 1;i <= 1000;i++){
			while(cnt[i] >= 4){
				c1++;
				c2--;
				if(c1>n){
					r1++;
					r2--;
					c1=1;
					c2=n;
					if(r1==mid) break;
				}//cout<<r1<<','<<c<<' '<<r2<<','<<c<<endl;
				mat[r1][c1] = mat[r2][c2] = i;
				cnt[i] -= 4;
			}
		}
		c1 = 1,c2 = 2;
		for(int i = 1;i <= 1000;i++){
			while(cnt[i] >= 2){
				c1++;
				c2--;
				if(c1==mid) break;
				//cout<<r1<<','<<c<<' '<<r2<<','<<c<<endl;
				mat[mid][c1] = mat[mid][c2] = i;
				cnt[i] -= 2;
			}
		}
		if(c1!=mid) ok = false;
		for(int i = 1;i <= 1000;i++){
			while(cnt[i] >= 2){
				c1++;
				c2--;
				if(c1==mid) break;
				//cout<<r1<<','<<c<<' '<<r2<<','<<c<<endl;
				mat[c1][mid] = mat[c2][mid] = i;
				cnt[i] -= 2;
			}
		}
		if(c1!=mid) ok =false;
		bool res = 0;
		for(int i = 1;i<=1000;i++){
			if(cnt[i]){
				mat[mid][mid] = i;
				cnt[i--];
				res++;
			}
		}
		if(res!=1) ok  = false;
	}
	else{
		int r1 = 1,r2 = n,c1 = 0,c2 = n+1;
		int mid = n/2;
		for(int i = 1;i <= 1000;i++){
			if(cnt[i]%4){
				ok = false;
				break;
			}
			for(int i = 1;i <= 1000;i++){
				while(cnt[i] >= 4){
					c1++;
					c2--;
					if(c1>n){
						r1++;
						r2--;
						c1=1;
						c2=n;
						if(r1==mid) break;
					}//cout<<r1<<','<<c<<' '<<r2<<','<<c<<endl;
					mat[r1][c1] = mat[r2][c2] = i;
					cnt[i] -= 4;
				}
			}
		}
		if(r1 != n/2 || c1 != n) ok = false;
	}
	if(ok){
		puts("YES");
		for(int i = 1;i <= n;i++){
			printf("%d",mat[i][1]);
			for(int j = 2;j <= n;j++){
				printf(" %d",mat[i][j]);
			}
			puts("");
		}
	}
	else puts("NO");
	return 0;
}
