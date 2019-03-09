#include<stdio.h>
#include<string.h>
        struct people
        {
                char id[10];
                int f;
        }p[100005];
        char id[10005][10];
        char idcheck[100005][10];
        char ans[100005][10];
        int ansi,anst;
int main()
{
        int N;
        int K;
        int M;
        char idtot[10];
        int tot,checktot;
        int flag,noflag;
        int i,j,k;
        while(scanf("%d%*c",&N)!=EOF)
        {
                memset(p,0,sizeof(p));
                memset(id,0,sizeof(id));
                memset(idcheck,0,sizeof(idcheck));
                memset(ans,0,sizeof(ans));
                tot=0;
                for(i=0;i<N;i++)
                {
                        scanf("%d",&K);
                        for(j=0;j<K;j++)
                        {
                                scanf("%s",&id[j]);
                                flag=0;
                                for(k=0;k<tot;k++)
                                {
                                        if(strcmp(p[k].id,id[j])==0)
                                        {
                                                p[k].f+=K;
                                                flag=1;
                                        }

                                }
                                if(!flag)
                                {
                                        strcpy(p[k].id,id[j]);
                                        p[k].f+=K;
                                        tot++;
                                }
                        }
                }
                scanf("%d%*c",&M);
                checktot=0;
                for(i=0;i<M;i++)
                {
                        memset(idtot,0,sizeof(idtot));
                        scanf("%s",idtot);
                        flag=1;
                        for(k=0;k<checktot;k++)
                                if(strcmp(idcheck[k],idtot)==0)
                                {
                                        flag=0;
                                        break;
                                }
                        if(flag)
                        {
                                strcpy(idcheck[k],idtot);
                                checktot++;
                        }
                }
                noflag=1;
                anst=0;
                for(i=0;i<checktot;i++)
                {
                        flag=1;
                        for(j=0;j<tot;j++)
                        {
                                if(strcmp(p[j].id,idcheck[i])==0)
                                {
                                        if(p[j].f<=1)
                                        {
                                                strcpy(ans[anst++],idcheck[i]);
                                                noflag=0;
                                        }
                                        flag=0;
                                        break;
                                }
                        }
                        if(flag)
                        {
                                strcpy(ans[anst++],idcheck[i]);
                                noflag=0;
                        }
                }
                if(noflag) printf("No one is handsome");
                else
                {
                        for(i=0;i<anst-1;i++)
                                printf("%s ",ans[i]);
                        printf("%s",ans[anst-1]);
                }
                printf("\n");
        }
        return 0;
}
