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
                for(i=5;i<=n;i+=5)
                {
                        j=i;
                        while(j%5==0)
                        {
                                ans++;
                                j/=5;
                        }
                }
                printf("%d\n",ans);
        }
        return 0;
}
