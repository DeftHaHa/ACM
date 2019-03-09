#include<stdio.h>
#include<math.h>
int main()
{
        int i;
        int n,flag;
        while(scanf("%d",&n)!=EOF)
        {
                if(n<=1)
                {
                        printf("no\n");
                        continue;
                }
                flag=1;
                for(i=2;i<=sqrt(n);i++)
                {
                        if(n%i==0)
                        {
                                flag=0;
                                break;
                        }
                }
                if(flag) printf("yes\n");
                else printf("no\n");
        }
        return 0;
}
