#include<stdio.h>
int main()
{
        int T;
        int m[6],n[6];
        int ic,is;
        int i;
        int sumc,sums;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d%d",&ic,&is);
                for(i=0;i<ic;i++)
                {
                        scanf("%d",&m[i]);
                        sumc+=m[i];
                }
                for(i=0;i<is;i++)
                {
                        scanf("%d",&n[i]);
                        sums+=n[i];
                }
                if(sumc>sums)
                        printf("Calem\n");
                else if(sumc==sums)
                        printf("Draw\n");
                else
                        printf("Serena\n");
                sumc=0;sums=0;
        }
        return 0;
}
