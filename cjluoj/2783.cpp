#include<cstdio>
using namespace std;
int main()
{
        int a,b;
        int i;
        int sum;
        while(scanf("%d%d",&a,&b)!=EOF)
        {
                sum=0;
                for(i=a;i<=b;i++)
                {
                        sum+=i;
                        printf("%5d",i);
                        if((i+1-a)%5==0) printf("\n");
                }
                if((i-a)%5!=0) printf("\n");
                printf("Sum = %d\n",sum);
        }
        return 0;
}
