#include<cstdio>
#include<cstring>
using namespace std;
struct people
        {
                char id[5];
                int f;
        }p[10005];
        int N;
        int K;
        char id[1005][6];
        int M;
        char idtot[6];
        char idcheck[10005][6];
int main()
{
        int tot,checktot;
        int flag,noflag;
        int i,j,k;
        while(scanf("%d%*c",&N)!=EOF)
        {
                memset(p,0,sizeof(p));
                memset(id,0,sizeof(id));
                memset(idcheck,0,sizeof(idcheck));
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
                for(i=0;i<checktot;i++)
                {
                        flag=1;
                        for(j=0;j<tot;j++)
                        {
                                if(strcmp(p[j].id,idcheck[i])==0)
                                {
                                        if(p[j].f<=1)
                                        {
                                                printf("%s",idcheck[i]);
                                                if(i!=M-1) printf(" ");
                                                noflag=0;
                                        }
                                        flag=0;
                                        break;
                                }
                        }
                        if(flag)
                        {
                                printf("%s",idcheck[i]);
                                noflag=0;
                                if(i!=M-1) printf(" ");
                        }
                }
                if(noflag) printf("No one is handsome");
                printf("\n");

        }
        return 0;
}
