#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll N;
int M;
struct Mat{
	ll n[105][105];
};
Mat mul(Mat a,Mat b){
	Mat res;
	memset(res.n,0,sizeof(res.n));
	for(int i = 1;i <= M;i++)
		for(int j = 1;j <= M;j++)
			for(int k = 1;k <= M;k++)
				res.n[i][j] = (res.n[i][j] + a.n[i][k]*b.n[k][j]%mod)%mod;
	return res;
}
Mat mat_pow(Mat A,ll n){
	Mat res;
	for(int i = 1;i <= M;i++)
		for(int j = 1;j <= M;j++)
			if(i==j) res.n[i][j] = 1;
			else res.n[i][j] = 0;
	while(n){
		if(n&1) res = mul(res,A);
		A = mul(A,A);
		n>>=1;
	}
	return res;
}
int main()
{
	scanf("%I64d%d",&N,&M);
	Mat A;
	memset(A.n,0,sizeof(A.n));
	A.n[1][1] = A.n[1][M] = 1;
	for(int i = 2;i <= M;i++) A.n[i][i-1] = 1;
	if(N < M) puts("1"); 
	else{
		A = mat_pow(A,N);
		printf("%I64d\n",A.n[1][1]);
	}
	
	return 0;
}
