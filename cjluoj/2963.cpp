#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
        char s[10];
        char ch1[4]={'i','x','c','m'};
        char ch2[3]={'v','l','d'};
        memset(s,0,sizeof(s));
        while(scanf("%s",s)!=EOF)
        {
                int l=strlen(s);
                printf("%s",s);
                for(int i=0;i<7-l;i++) printf(" ");
                if(l==4&&s[0]>'1')
                {
                        for(int i=0;i<s[0]-'0';i++)
                                printf("m");
                        s[0]='0';
                }
                for(int i=0;i<l;i++)
                {
                        if(s[i]<='3')
                        {
                                for(int j=0;j<s[i]-'0';j++)
                                        printf("%c",ch1[l-i-1]);
                        }
                        else if(s[i]>'3'&&s[i]<='5')
                        {
                                for(int j=0;j<'5'-s[i];j++)
                                        printf("%c",ch1[l-i-1]);
                                printf("%c",ch2[l-i-1]);
                        }
                        else if(s[i]>'5'&&s[i]<='8')
                        {
                                printf("%c",ch2[l-i-1]);
                                for(int j=0;j<s[i]-'5';j++)
                                        printf("%c",ch1[l-i-1]);
                        }
                        else if(s[i]>'8'&&s[i]<='9')
                        {
                                for(int j=0;j<'9'-s[i]+1;j++)
                                        printf("%c",ch1[l-i-1]);
                                printf("%c",ch1[l-i]);
                        }
                }
                printf("\n");
                memset(s,0,sizeof(s));
        }
        return 0;
}
