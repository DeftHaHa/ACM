#include<stdio.h>
#include<string.h>
int main()
{
        int t=0;
        float n,sum=0;
        while(1)
        {
                scanf("%f",&n);
                if(n==-1) break;
                sum+=n;
                t++;
        }
        printf("%.2f",sum/t);
        return 0;
}
