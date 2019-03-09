#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
        int n;
        int ans;
        int j;
        int i;
        while(scanf("%d",&n)!=EOF)
        {
                ans=0;
                while(n)
                {
                        ans+=n/5;
                        n/=5;
                }
                printf("%d\n",ans);
        }
        return 0;
}
