#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
        int z,n;
        int i,j;
        int a[10],b[10];
        char c[6]={'A','B','C','D','E','F'};
        scanf("%d",&z);
        if(z==0) {printf("0\n0\n");return 0;}
        n=z;
        for(i=0;i<10;i++)
        {
                a[9-i]=n-n/8*8;
                n=n/8;
                if(n==0) break;
        }
        for(j=9-i;j<10;j++)
                printf("%d",a[j]);
        printf("\n");


        n=z;
        for(i=0;i<10;i++)
        {
                b[9-i]=n-n/16*16;
                n=n/16;
                if(n==0) break;
        }
        for(j=9-i;j<10;j++)
        {
                if(b[j]>10) printf("%c",c[b[j]-10]);
                else printf("%d",b[j]);
        }
        return 0;

}
