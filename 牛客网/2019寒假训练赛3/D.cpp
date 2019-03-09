#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct P{
    int a,b;
    double w;
}p[100005];
bool cmp(P a,P b){
    if(a.w != b.w) return a.w < b.w;
    return a.a > b.a;
}
int main()
{
    int N;
    scanf("%d",&N);
    ll sum = 0;
    for(int i = 0;i < N;i++){
        scanf("%d%d",&p[i].a,&p[i].b);
        sum += p[i].b;
        p[i].w = (double)p[i].a/(double)p[i].b;
    }
    sort(p,p+N,cmp);
    ll ans = 0;
    for(int i = 0;i < N;i++){
        sum -= p[i].b;
        ans += sum * p[i].a;
    }
    printf("%lld\n",ans);
    return 0;
}
