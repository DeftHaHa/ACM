#include<cstdio>
using namespace std;
int main()
{
        int N;
        int i;
        int t,tot;
        scanf("%d",&N);
        while(N--)
        {
                tot=0;
                scanf("%d",&i);
                tot+=i;
                while(i--)
                {
                        scanf("%d",&t);
                        tot+=t;
                }
                printf("%d\n",tot);
        }
        return 0;
}
