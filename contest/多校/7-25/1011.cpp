#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        long long n,k;
        int c=1;
        long long i,j;
        while(scanf("%lld%lld",&n,&k)!=EOF)
        {
                if(k<=n) printf("Case #%d: %d\n",c++,k);
                else
                {
                        k-=n;
                        n-=1;
                        i=k/n;
                        j=k%n;
                        if(j==0) j=n+1;
                        if(i&1&&j==0) j-=1;

                        printf("Case #%d: %d\n",c++,j);

                }
        }
        return 0;
}
