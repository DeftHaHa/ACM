#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
        char s[105];
        memset(s,0,sizeof(s));
        int T;
        while(scanf("%d",&T)!=EOF)
        {
                if(T==0) break;
                while(T--)
                {
                        scanf("%s",&s);
                        char ans[105];
                        memset(ans,'Z',sizeof(ans));
                        int l=strlen(s);
                        bool flag;
                        for(int st=0;st<l;st++)
                        {
                                flag=false;
                                for(int i=st,j=0;i<st+l;i++,j++)
                                {
                                        if(s[i%l]>ans[j])
                                        {
                                                flag=false;
                                                break;
                                        }
                                        else if(s[i%l]<ans[j])
                                        {
                                                flag=true;
                                                break;
                                        }
                                }
                                if(flag)
                                {
                                        for(int i=st,j=0;i<st+l;i++,j++)
                                        {
                                                ans[j]=s[i%l];
                                        }
                                }
                        }
                        for(int i=0;i<l;i++) printf("%c",ans[i]);
                        printf("\n");
                        memset(s,0,sizeof(s));
                }
        }
        return 0;
}
