#include<stdio.h>
int main()
{
        int va,vb;
        int N;
        int pa[105],da[105],pb[105],db[105];
        int suma,sumb;
        int flaga,flagb;
        while(scanf("%d%d",&va,&vb)!=EOF)
        {
                int i;
                suma=0;sumb=0;
                flaga=flagb=0;
                scanf("%d",&N);
                for(i=1;i<=N;i++)
                        scanf("%d%d%d%d",&pa[i],&da[i],&pb[i],&db[i]);
                for(i=1;i<=N;i++)
                {
                        if((da[i]==pa[i]+pb[i])&&(db[i]!=pa[i]+pb[i]))
                                suma++;
                        else if((db[i]==pa[i]+pb[i])&&(da[i]!=pa[i]+pb[i]))
                                sumb++;
                        if(suma>va)
                        {
                                flaga=1;
                                break;
                        }
                        else if(sumb>vb)
                        {
                                flagb=1;
                                break;
                        }
                }
                if(flaga) printf("A\n%d\n",sumb);
                else if(flagb) printf("B\n%d\n",suma);
        }
        return 0;
}
