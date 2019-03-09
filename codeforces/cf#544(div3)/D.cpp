#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<pair<int,int>,int> Map;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int a[200005],b[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	int ans = 0;
	int cnt1 = 0,cnt2 = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&b[i]);
		if(a){
			int GCD = gcd(abs(a[i]),abs(b[i]));
			if(a[i] < 0) a[i] = -a[i],b[i] = -b[i];
			a[i] = abs(a[i]);
			//cout<<a[i]/GCD<<' '<<b[i]/GCD<<endl;
			if(b[i]==0 && a[i]==0) cnt2++;
			else if(a[i]){
				Map[make_pair(a[i]/GCD,b[i]/GCD)]++;
				ans = max(ans,Map[make_pair(a[i]/GCD,b[i]/GCD)]);
			}
		}
	}
	printf("%d\n",ans+cnt2);
	
	return 0;
}
