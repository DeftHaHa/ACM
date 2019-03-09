#include<stdio.h>
int main()
{
        int n;
        int k;
        while(scanf("%d",&n)!=EOF)
        {
                if(n<0||n>100)
                {
                        printf("input error\n");
                        continue;
                }
                k=n/5;
                switch(k)
                {
                        case 20:printf("A+\n");break;
                        case 19:printf("A+\n");break;
                        case 18:printf("A\n");break;
                        case 17:printf("A-\n");break;
                        case 16:printf("B+\n");break;
                        case 15:printf("B\n");break;
                        case 14:printf("B-\n");break;
                        case 13:printf("C+\n");break;
                        case 12:printf("C\n");break;
                        case 11:printf("C-\n");break;
                        case 10:printf("D\n");break;
                        default:printf("F\n");break;
                }
        }
        return 0;
}
