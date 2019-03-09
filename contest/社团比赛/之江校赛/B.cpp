#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct people
{
        char name[20];
        int num;
}p[1005];
bool cmp(people a,people b)
{
        return a.num>b.num;
}
int main()
{
        int n;
        int t;
        int flag;
        int i;
        char piao[20];
        while(scanf("%d",&n)!=EOF)
        {
                t=0;flag=0;
                memset(p,0,sizeof(p));
                while(n--)
                {
                        memset(piao,0,sizeof(piao));
                        scanf("%s",piao);
                        for(i=0;i<t;i++)
                        {
                                flag=0;
                                if(strcmp(p[i].name,piao)==0)
                                {
                                        p[i].num++;
                                        flag=1;
                                }
                        }
                        if(!flag)
                        {
                                strcpy(p[t].name,piao);
                                p[t].num++;
                                t++;
                        }
                }
                sort(p,p+t+1,cmp);
                printf("%s\n",p[0].name);
        }
        return 0;
}
