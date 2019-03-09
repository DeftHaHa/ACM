#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        char a_in_1[405],a_in_2[405];
        int a_1[405]={0},a_2[405]={0};
        int i;
        int j;
        int flag;
        int l_1,l_2;
        int sum;
        int ans[405]={0};
        memset(a_in_1,0,sizeof(a_in_1));
        memset(a_in_2,0,sizeof(a_in_2));
        while(scanf("%s%s",a_in_1,a_in_2)!=EOF)
        {

                l_1=strlen(a_in_1);
                l_2=strlen(a_in_2);
                for(i=l_1-1;i>=0;i--)
                {
                        a_1[l_1-1-i]=a_in_1[i]-'0';
                }
                for(i=l_2-1;i>=0;i--)
                {
                        a_2[l_2-1-i]=a_in_2[i]-'0';
                }
                flag=0;
                for(i=0;i<405;i++)
                {
                        sum=ans[i]+a_1[i]+a_2[i];
                        if(sum>0) flag=1;
                        ans[i]=sum%10;
                        ans[i+1]+=sum/10;
                }
                if(flag)
                {
                        for(i=405;i>=0;i--)
                                if(ans[i]!=0)  break;
                        for(j=i;j>=0;j--)
                                printf("%d",ans[j]);
                }
                else if(!flag)
                        printf("0");
                printf("\n");
                memset(a_in_1,0,sizeof(a_in_1));
                memset(a_in_2,0,sizeof(a_in_2));
                memset(a_1,0,sizeof(a_1));
                memset(a_2,0,sizeof(a_2));
                memset(ans,0,sizeof(ans));
        }
        return 0;
}
