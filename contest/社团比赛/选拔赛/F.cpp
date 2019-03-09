#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        char a[105];
        int l;
        int i;
        int flag;
        int ok;
        while(scanf("%s",&a)!=EOF)
        {
                l=strlen(a);
                flag=0;ok=1;
                if(a[0]=='_')
                {
                        printf("Unknown!\n");
                        ok=0;
                        continue;
                }
                for(i=0;i<l;i++)
                {
                        if(flag==1&&a[i]=='_')
                        {
                                ok=0;
                        }
                        else if(flag==2&&a[i]>='A'&&a[i]<='Z')
                        {
                                ok=0;
                        }
                        else if((a[i]>'Z'||a[i]<'A')&&(a[i]<'a'||a[i]>'z')&&a[i]!='_')
                        {
                                ok=0;
                                break;
                        }
                        else if(a[i]=='_') flag=2;              // cpp
                        else if(a[i]>='A'&&a[i]<='Z') flag=1;   // java
                }
                if(!ok)
                {
                        printf("Unknown!\n");
                }
                else if(ok)
                {
                        if(flag==0) printf("%s\n",a);
                        else if(flag==1)
                        {
                                for(i=0;i<=l;i++)
                                {
                                        if(a[i]>='A'&&a[i]<='Z')
                                        {
                                                printf("_%c",a[i]+32);
                                        }
                                        else
                                                printf("%c",a[i]);
                                }
                                printf("\n");
                        }
                        else if(flag==2)
                        {
                                for(i=0;i<l;i++)
                                {
                                        if(a[i]=='_')
                                        {
                                                i++;
                                                printf("%c",a[i]-32);
                                        }
                                        else
                                                printf("%c",a[i]);
                                }
                                printf("\n");
                        }
                }
        }
        return 0;
}
