#include<stdio.h>
int main()
{
        int N,n;
        char ch;
        int i,j;
        while(scanf("%d %c",&N,&ch)!=EOF)
        {
                if(N&1) n=N/2+1;
                else n=N/2;
                for(i=0;i<n;i++)
                {
                        for(j=0;j<N;j++)
                                printf("%c",ch);
                        printf("\n");
                }
        }
        return 0;
}
