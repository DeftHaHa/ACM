#include<cstdio>
#include<cstring>
int main()
{
        int M,N;
        char ch;
        int total;
        int i;
        while(1)
        {
                scanf("%d%d",&N,&M);
                if(M==0&&N==0)  break;
                total=0;
                for(i=0;i<N*(M+1)+1;i++)
                {
                        ch=getchar();
                        if(ch=='*') total++;
                }
                printf("%d\n",total);
        }

        return 0;
}
