#include <map>  
#include <set>  
#include <stack>  
#include <queue>  
#include <cmath>  
#include <ctime>  
#include <vector>  
#include <cstdio>  
#include <cctype>  
#include <cstring>  
#include <cstdlib>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
#define INF 0x3f3f3f3f  
#define inf -0x3f3f3f3f  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
#define mem0(a) memset(a,0,sizeof(a))  
#define mem1(a) memset(a,-1,sizeof(a))  
#define mem(a, b) memset(a, b, sizeof(a))  
typedef long long ll;  
char s[100];  
ll num[66197];  
int cnt=0;  
  
void dfs(int cnt1,int cnt2,int len,ll number){  
    if(cnt1==len&&cnt2==len){  
        num[cnt++]=number;  
        return ;  
    }  
    if(cnt1<len)  
        dfs(cnt1+1,cnt2,len,number*10+4);  
    if(cnt2<len)  
        dfs(cnt1,cnt2+1,len,number*10+7);  
}  
  
int main(){  
    int _;  
    for(int i=1;i<=9;i++)  
        dfs(0,0,i,0);  
    scanf("%d",&_);  
    while(_--){  
        ll n;  
        scanf("%lld",&n);  
        if(n>num[cnt-1])  
            puts("44444444447777777777");  
        else{  
            int id=lower_bound(num,num+cnt,n)-num;  
            printf("%lld\n",num[id]);  
        }  
    }  
    return 0;  
}  
