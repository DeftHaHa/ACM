#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int b[100005];
int ans[100005];
struct Child{
	int id,h;
}c[100005];
bool cmp(Child a,Child b){
	return a.h < b.h;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++){
		scanf("%d",&c[i].h);
		c[i].id = i+1;
	} 
	for(int i = 0;i < m;i++) scanf("%d",&b[i]);
	sort(c,c+n,cmp);
	sort(b,b+m);
	int pos = 0;
	memset(ans,0,sizeof(ans));
	for(int i = 0;i < n;i++){
		while(pos < m && b[pos] <= c[i].h){
			ans[c[i].id]++;//cout<<i <<" "<<pos <<' '<<c[i].h<<' '<<b[pos]<<endl;
			pos++;
		}
	}
	for(int i = 1;i <= n;i++) printf("%d\n",ans[i]);
	
	return 0;
}
