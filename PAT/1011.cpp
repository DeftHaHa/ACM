#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll f(string s,int len,ll r)
{
	ll w = 1,res = 0;
	for(int i = len-1;i >= 0;i--){
		if(s[i]>='0'&&s[i]<='9') res += w*(s[i]-'0');
		else res += w*(s[i]-'a'+10);
		if(res < 0||w < 0) return -1;
		w*=r;
	}
	return res;
}
int main()
{
	string s1,s2;
	ll tag,r;
	cin>>s1>>s2>>tag>>r;
	if(tag==2) swap(s1,s2);
	int len1 = s1.length(),len2 = s2.length();
	ll num1 = f(s1,len1,r);
	int maxr = 1;
	for(int i  = 0;i < len2;i++){
		maxr = max(maxr,s2[i]>='0'&&s2[i]<='9' ? s2[i]-'0':s2[i]-'a'+10);
	}
	ll l  = max((ll)maxr+1,(ll)2);
	r = num1+1;
	ll ans = -1;
	while(l <= r){
		ll mid = (l+r)/2;
		ll num2 =  f(s2,len2,mid);
		if(num2==-1 || num2>num1 ) r = mid-1;
		else if(num2<num1) l = mid+1; 
		else{
			ans = mid;
			break;
		}
	}
	if(ans!=-1) printf("%lld\n",ans);
	else  puts("Impossible");
	return 0;
}
