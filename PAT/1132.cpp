#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
	int N;
	scanf("%d",&N);
	string s;
	ll a,b,z;
	while(N--){
		cin>>s;
		int len = s.length();
		a = b = z = 0;
		for(int i = 0;i < len / 2;i++){
			a = a*10 + (s[i]-'0');
			z = z*10 + (s[i]-'0');
		}
		for(int i = len/2;i < len;i++){
			b = b*10 + (s[i]-'0');
			z = z*10 + (s[i]-'0');	
		}
		//cout<<a<<' '<<b<<' '<<z<<endl;
		if((a*b)==0||(z!=0  && z%(a*b))) puts("No");
		else puts("Yes");
	}
	return 0;
}
