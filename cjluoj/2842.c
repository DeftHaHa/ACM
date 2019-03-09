#include<stdio.h>
int main()
{
        float a,c;
        char b;
        while(scanf("%f%c%f",&a,&b,&c)!=EOF)
        {
                if(b=='+') printf("%.2f\n",a+c);
                else if(b=='-') printf("%.2f\n",a-c);
                else if(b=='*') printf("%.2f\n",a*c);
                else if(b=='/')
                {
                        if(c==0) printf("divisor is 0\n");
                        else printf("%.2f\n",a/c);
                }
        }
}
