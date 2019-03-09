#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
        int a[10];
        int M,N;
        int i;
        for(i=0;i<=9;i++)
                a[i]=i;
        scanf("%d%d",&N,&M);
        do
        {
                if(a[1]<=M+1)
                {
                        for(i=1;i<=N;i++)
                        {
                                printf("%d",a[i]);
                        }
                        printf("\n");
                }

        }while(next_permutation(&a[1],&a[1]+N));
        return 0;
}
