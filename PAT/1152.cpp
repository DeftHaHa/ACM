#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
bool is_prime(long long n){
	if(n < 2) return false;
	long long r = sqrt(n);
	for(int i = 2;i <= r;i++){
		if(n%i == 0) return false;
	}
	return true;
}
int main()
{
	string s;
	int L,K;
	cin>>L>>K>>s;
	int tag = L-1;
	for(int i = 0;i < L;i++){
		if(s[i]!='0'){
			tag = i;
			break;
		}
	}
	if(L - tag + 1< K || !L||!K){
		printf("404\n");
		return 0;
	}
	bool flag = false;
	string ans;
	long long temp = 0;
	for(int i = tag;i < K+tag;i++) temp = temp*10 + (s[i] - '0');
	if(is_prime(temp)){
		flag = true;
		ans = s.substr(tag,K);
	}
	long long x = 1;
	for(int i = 0;i < K-1;i++) x*=10;
	if(!flag)
	for(int i = tag+1 ; i <= L-K+1;i++){
		temp = temp%x;
		temp = temp*10 + (s[i+K-1] - '0');
		//cout<<temp<<endl;
		if(is_prime(temp)){
			flag = true;
			ans = s.substr(i,K);
			break;
		}
	}
	if(!flag) printf("404\n");
	else cout<<ans<<endl;
	return 0;
}
