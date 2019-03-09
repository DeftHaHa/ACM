#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
vector<long long> v;
long long a,b;
long long t;
int flag;
void dfs(long long n)
{

        if(n==b)
        {
                if(!flag)
                {
                        v.push_back(n);
                        flag=1;
                        printf("YES\n");
                        long long l=v.size();
                        printf("%lld\n",l);
                        for(long long i=0;i<l;i++)
                        {
                                printf("%lld",v[i]);
                                printf(" ");
                        }
                        cout<<endl;
                        return;
                }
        }
        else
        {
                v.push_back(n);
                t=n*2;
                if(t<=b) dfs(t);
                t=n*10+1;
                if(t<=b) dfs(t);
                v.pop_back();
        }
        return;
}
int main()
{
        while(scanf("%lld%lld",&a,&b)!=EOF)
        {
                flag=0;
                dfs(a);
                if(!flag)
                        printf("NO\n");
                vector<long long> x;
                v.swap(x);
        }
        return 0;
}
