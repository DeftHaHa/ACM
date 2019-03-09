#include<stdio.h>
int main()
{
        int n;
        int i,max,min,t,imax=0,imin=0;
        int a[10];
        scanf("%d",&n);
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        max=a[0];
        for(i=0;i<n;i++)
        {
                if(a[i]>max)
                {
                        max=a[i];
                        imax=i;
                }
        }
        t=max;
        a[imax]=a[n-1];
        a[n-1]=max;
        min=a[0];
        for(i=0;i<n;i++)
        {
                if(a[i]<min)
                {
                        min=a[i];
                        imin=i;
                }
        }
        t=min;
        a[imin]=a[0];
        a[0]=t;
        for(i=0;i<n-1;i++)
                printf("%d ",a[i]);
        printf("%d",a[n-1]);
        return 0;
}
