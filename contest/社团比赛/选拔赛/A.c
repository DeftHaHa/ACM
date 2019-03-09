#include<stdio.h>
#include<string.h>
int main()
{
        char number_1[400],number_2[400];
        int   ans[401]={0};
        int i;
        int l_1,l_2;
        int flag,k;
        while(scanf("%s%s",&number_1,&number_2)!=EOF)
        {
                l_1=strlen(number_1);
                l_2=strlen(number_2);
                if(l_1>l_2)
                {
                        for(l_1;l_1>=0;l_1--)
                        {
                                if(l_2-1>=0)
                                {
                                        if(flag)
                                                k=(number_1[l_1-1]-'0')+(number_2[l_2-1]-'0')+1;
                                        else
                                                k=(number_1[l_1-1]-'0')+(number_2[l_2-1]-'0');
                                        if(k<10)
                                                ans[l_1]=k;
                                        else if(k>=10)
                                        {
                                                ans[l_1]=k%10;
                                                flag=1;
                                        }
                                }
                                else
                                {
                                        if(flag)
                                                k=(number_1[l_1-1]-'0')+1;
                                        else
                                                k=(number_1[l_1-1]-'0');
                                        if(k<10)
                                                ans[l_1]=k;
                                        else if(k>=10)
                                        {
                                                ans[l_1]=k%10;
                                                flag=1;
                                        }
                                }
                                l_2--;flag=0;

                        }

                }
                for(i=0;i<=401;i++)
                        if(ans[i]!=0) printf("%d",ans[i]);
        }
        return 0;
}
