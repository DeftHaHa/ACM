#include<stdio.h>
int main()
{
        int m,sum=0;
        while(scanf("%d",&m)!=EOF)
        {
                for(m;m<=100;m++)
                {
                        sum+=m;
                }
                printf("%d\n",sum);
        }
        return 0;
}
