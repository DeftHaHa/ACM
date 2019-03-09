#include<stdio.h>
#include<string.h>
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
                for(i=0;i<l;i++)
                {
                        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||a[i]=='_')
                        {
                                if(flag==1&&a[i]=='_')
                                {
                                        printf("Unknown!\n");
                                        ok=0;
                                }
                                else if(flag==2&&a[i]>='A'&&a[i]<='Z')
                                {
                                        printf("Unknown!\n");
                                        ok=0;
                                }
                                else if(a[i]=='_') flag=2;
                                else if(a[i]>='A'&&a[i]<='Z') flag=1;
                        }
                        else
                        {
                                if(flag==1&&a[i]=='_')
                                {
                                        printf("Unknown!\n");
                                        ok=0;
                                        break;
                                }
                        }
                }
                if(ok)
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
