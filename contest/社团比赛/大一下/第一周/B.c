#include<stdio.h>
#include<string.h>
int max(a,b)
{
        if(a>b) return a;
        else return b;
}
int min(a,b)
{
        if(a<b) return a;
        else return b;
}
int main()
{
        int x_1,y_1,x_2,y_2;
        int x_3,y_3,x_4,y_4;
        int N;
        int i,j;
        int att[100][100];
        scanf("%d",&N);
        while(N--)
        {
                scanf("%d%d%d%d%d%d%d%d",&x_1,&y_1,&x_2,&y_2,&x_3,&y_3,&x_4,&y_4);
                memset(att,0,sizeof(att));
                for(i=min(x_1,x_2);i<=max(x_1,x_2);i++)
                        for(j=min(y_1,y_2);j<=max(y_1,y_2);j++)
                                att[i][j]=1;
                for(i=min(x_3,x_4);i<=max(x_3,x_4);i++)
                        {
                                for(j=min(y_3,y_4);j<=max(y_3,y_4);j++)
                                {
                                        if(att[i][j]==1)
                                        {
                                                printf("Hit\n");
                                                break;
                                        }
                                }
                                if(att[i][j]==1)
                                        break;
                        }
                if(i>=x_4,j>=y_4) printf("Miss\n");
        }
        return 0;
}
