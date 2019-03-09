#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[10005],m[10005];
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	ll res = exgcd(b,a%b,x,y);
	ll t = x;
	x = y;
	y = t-a/b*y;
	return res;
}
ll exCRT(ll a[],ll m[],int n){
	ll A = a[1],M=m[1],x,y,d,t;
	for(int i = 2;i <= n;i++){
		d = exgcd(M,m[i],x,y); 
		if((a[i]-A)%d) return -1;  //无解 m1*x-m2*y =a2-a1  ->  c = a2-a1
		t = m[i]/d;
		x = (x%t+t)%t; 		//转正数  		 
		x = ((a[i]-A)/d*x%t+t)%t;//最小正解x0
		ll LCM = M*t;   		//LCM (m1,m2)
		A = (x*M+A)%LCM;  	//a1 = x0*m1+a1   当前x的一个特解
		M = LCM;     		//m1 = LCM(m1,m2)  求x的通解加上lcm*k
	}
	return A;
}
int main()
{
	int k;
	scanf("%d",&k);
	for(int i = 1;i <= k;i++) scanf("%lld%lld",&m[i],&a[i]);
	printf("%lld\n",exCRT(a,m,k));
	return 0;
}
