#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll l = 1032,r = 12302135942453,d = 234;
	ll ans = r/d - (l-1)/d;
	cout<<ans<<endl;
	
	return 0;
}
