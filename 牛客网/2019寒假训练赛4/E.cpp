#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
string div(string a,int b)
{
    string r,ans;
    int d=0;
    if(a=="0") return a;
    int len = a.length();
    for(int i=0;i<len;i++)
    {
        r+=(d*10+a[i]-'0')/b+'0';
        d=(d*10+(a[i]-'0'))%b;
    }
    int p=0;
    len = r.length();
    for(int i=0;i<len;i++) if(r[i]!='0') {p=i;break;}
    return r.substr(p);
}
int main()
{
    string n, m;
    cin>>n>>m;
    ll ans = 1,a = 2;
    while(m!="0")
    {
    	if((*(m.end()-1)-'0')%2) ans = ans*a%mod;
    	a = a*a%mod;
    	m = div(m,2);
	}
	printf("%lld\n",ans);
    return 0;
}
