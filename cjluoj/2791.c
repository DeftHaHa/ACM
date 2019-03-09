#include<stdio.h>
#include<string.h>
int main()
{
        char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
        int v[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        int N;
        int i,j;
        char id[100][18];
        int sum;
        int k[105];
        int flag;
        while(scanf("%d%*c",&N)!=EOF)
        {
                flag=0;
                memset(k,0,sizeof(k));
                memset(id,0,sizeof(id));
                for(i=0;i<N;i++)
                {
                        sum=0;
                        for(j=0;j<17;j++)
                        {
                                scanf("%c",&id[i][j]);
                                if(id[i][j]>'9'||id[i][j]<'0')
                                {
                                        k[i]=1;
                                        flag=1;
                                }
                                sum+=(id[i][j]-'0')*v[j];
                        }
                        scanf("%c%*c",&id[i][17]);
                        if(M[sum%11]!=id[i][17])
                        {
                                k[i]=1;
                                flag=1;
                        }
                }
                if(flag)
                        for(i=0;i<N;i++)
                        {
                                if(k[i]==1)
                                {
                                        for(j=0;j<18;j++)
                                                printf("%c",id[i][j]);
                                        printf("\n");
                                }
                        }
                else
                        printf("All passed\n");
        }
        return 0;
}
