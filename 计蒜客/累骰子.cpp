#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod  = 1e9+7;
struct Mat{
	ll n[6][6];
};
Mat mul(Mat a,Mat b,int r,int t,int c){
	Mat res;
	memset(res.n,0,sizeof(res.n));
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			for(int k = 0;k < t;k++){
				res.n[i][j] = (res.n[i][j] + (a.n[i][k] * b.n[k][j])%mod)%mod;
			}
		}
	}
	return res;
}
Mat mat_pow(Mat a,int b){
	Mat res;
	memset(res.n,0,sizeof(res.n));
	for(int i = 0;i < 6;i++) res.n[i][i] = 1;
	while(b){
		if(b&1) res = mul(res,a,6,6,6);
		a = mul(a,a,6,6,6);
		b>>=1;
	}
	return res;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	Mat A;
	for(int i = 0;i < 6;i++){
		for(int j = 0;j < 6;j++){
			A.n[i][j] = 4;
		}
	}
	int d[7] = {0,4,5,6,1,2,3};
	while(m--){
		scanf("%d%d",&a,&b);
		A.n[a-1][d[b]-1] = A.n[b-1][d[a]-1] = 0;
	}
	if(n==1) puts("24");
	else{
		A = mat_pow(A,n-1);
	 	ll sum = 0;
	 	for(int i = 0;i < 6;i++){
	 		for(int j = 0;j < 6;j++){
	 			sum  = (sum + A.n[i][j]*4)%mod;	
			}
		 }
		printf("%lld\n",sum);	
	}
	return 0;
}
