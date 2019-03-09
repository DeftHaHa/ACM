#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        char s[505];
        char t[505];
        int i,j;
        int lt;
        int tot;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        while(scanf("%s%s",s,t)!=EOF)
        {

                l=strlen(t);
                j=0;
                tot=0;
                for(i=0;i<l;i++)
                {
                        for(;s[j]!='\0';j++)
                        {
                                if(t[i]==s[j])
                                {
                                        tot++;
                                        break;
                                }
                        }
                }
                if(tot==l) printf("yes\n");
                else printf("no\n");
                memset(s,0,sizeof(s));
                memset(t,0,sizeof(t));

        }
        return 0;
}
