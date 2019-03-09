#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef struct
{
        int k;
        int num;
}puke;
int main()
{
        puke p[10005];
        int N;
        int K;
        int i,j;
        int a;
        int kind=0;
        while(cin>>N)
        {
                memset(p,0,sizeof(p));
                for(i=0;i<N;i++)
                {
                        scanf("%d",&a);
                        for(j=0;j<10005;j++)
                        {
                                if(p[j].k==0)
                                {
                                        p[j].k=a;
                                        p[j].num=1;
                                        break;
                                }
                                else if(p[j].k==a)
                                {
                                        p[j].num++;
                                        break;
                                }
                        }
                }
                kind=j+1;
                scanf("%d",&K);
                for(i=0;p[i].k!=0;i++)
                {
                        while(p[i].num>1)
                        {
                                p[i].num--;
                                K--;
                        }
                        if(K<=0) break;
                }
                if(K<=0)
                        cout<<kind<<endl;
                else
                        printf("%d\n",kind-K);
        }
        return 0;
}
