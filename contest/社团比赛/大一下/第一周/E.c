#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
        return *(int*)b-*(int *)a;
}
int main()
{
        int N,M;
        int i;
        int xiao,da;
        int stu[200000];
        while(1)
        {
                memset(stu,0,sizeof(stu));
                scanf("%d",&N);
                if(N==0) break;
                for(i=1;i<=N;i++)
                        scanf("%d",&stu[i]);
                qsort(&stu[1],N,sizeof(stu[1]),cmp);
                scanf("%d",&M);
                while(M--)
                {
                        scanf("%d%d",&xiao,&da);
                        for(i=1;i<=N;i++)
                        {
                                if(stu[i]<=da&&stu[i]>=xiao)
                                {
                                        printf("%d ",i);
                                        break;
                                }
                        }
                        if(i>N) printf("0 ");
                        for(i=N;i>=1;i--)
                        {
                                if(stu[i]>=xiao&&stu[i]<=da)
                                {
                                        printf("%d\n",i);
                                        break;
                                }
                        }
                        if(i<1) printf("0\n");
                }
        }
        return 0;
}
