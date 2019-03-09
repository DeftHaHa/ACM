#include<stdio.h>
int main()
{
        int n;
        int d;
        while(scanf("%d",&n)!=EOF)
        {
                if(n==1)
                {
                        scanf("%d",&d);
                        printf("%.2f\n",100+0.36*d/365);
                }
                else if(n==2)
                        printf("102.25\n");
                else if(n==3)
                        printf("109.99\n");
                else if(n==4)
                        printf("118.00\n");
                else printf("Input error\n");
        }
}
