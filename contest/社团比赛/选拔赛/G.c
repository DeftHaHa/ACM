#include<stdio.h>
int main()
{
        int l1,l2;
        int i,j,k_1,k_2;
        int ans_0=0,ans=0;
        int a[180],b[180];
        scanf("%d%d",&l1,&l2);
        for(i=0;i<l1;i++)
        {
               scanf("%d",&a[i]);
        }
        for(i=1;i<l2;i++)
        {
                scanf("%d",&b[i]);
        }
        for(i=0;i<l1;i++)
        {
                for(j=0;j<l2;j++)
                {
                        if(a[i]==b[j])
                        {
                                k_1=i;
                                for(k_2=j;k_2<l2;k_2++)
                                {
                                        if(a[k_1]==b[k_2]) ans_0++;
                                        else break;
                                        k_1++;
                                }
                                if(ans_0>ans) ans=ans_0;
                                ans_0=0;
                        }
                }
        }
        printf("%d\n",ans);
        return 0;
}
