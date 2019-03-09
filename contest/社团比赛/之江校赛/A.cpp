#include<cstdio>
int main()
{
        int T;
        int K,N;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d%d",&K,&N);
                if(K%(N+1)==0) printf("Z\n");
                else    printf("L\n");
        }
        return 0;
}
