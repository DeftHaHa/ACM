#include<cstdio>
using namespace std;
int main()
{
        long long F;
        while(scanf("%lld",&F)!=EOF)
        {
                printf("Celsius = %lld\n",5*(F-32)/9);
        }
        return 0;
}
