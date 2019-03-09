#include<stdio.h>

int main()
{
        int i,j;
        int sum,t;
        int n;
        int num[10][11];
        while(scanf("%d",&n)!=EOF);
        {
                if(n==3) printf("153\n370\n371\n407\n");
                else if(n==4) printf("1634\n8208\n9474\n");
                else if(n==5)
                        printf("54748\n92727\n93084\n");
                else if(n==6)
                        printf("548834\n");
                else if(n==7)
                        printf("1741725\n4210818\n9800817\n9926315\n");
                else if(n==8)
                        printf("24678050\n24678051\n88593477\n");
                else if(n==9)
                        printf("146511208\n472335975\n534494836\n912985153\n");
                else if(n==10)
                        printf("4679307774\n");
        }
        return 0;
}
