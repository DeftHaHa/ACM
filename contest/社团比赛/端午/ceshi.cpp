#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int mm(int a,int b)
{
        if(a>b) return a;
        else return b;
}
int main()
{
        int left,right;
        int k;
        int l;
        int l_b,l_c;
        char a[405]={0};
        int sum=0;
        char b[405]={0};
        char c[405]={0};
        char d[405]={0};
        char ans[405]={0};
        int i;

        l=strlen(a);

        int s,flag=0;
        int MM=100;
        for(i=0;i<MM+1;i++)
        {
                if(c[i]!='\0'&&d[i]!='\0')
                {
                        s=(c[i]-'0')+(d[i]-'0')+flag;
                        if(s>=10)
                        {
                                flag=1;
                                ans[i]='0'+s%10;
                        }
                        else
                        {
                                flag=0;
                                ans[i]='0'+s;
                        }
                }
                else if(c[i]=='\0'&&d[i]!='\0')
                {
                        if(flag)
                        {
                                s=(d[i]-'0')+flag;
                                if(s>=10)
                                {
                                        flag=1;
                                        ans[i]='0'+s%10;
                                }
                                else    flag=0;
                        }
                        else break;
                }
                else if(d[i]=='\0'&&c[i]!='\0')
                {
                        if(flag)
                        {
                                s=(c[i]-'0')+flag;
                                if(s>=10)
                                {
                                        flag=1;
                                        ans[i]='0'+s%10;
                                }
                                else    flag=0;
                        }
                        else break;
                }
                else if(d[i]=='\0'&&c[i]=='\0')
                {
                        if(!flag) break;
                        else ans[i]='1';
                }
        }         printf("%s\n%s\n",c,d);
        i-=1;
        for(;i>=0;i--)
        {
                printf("%c",ans[i]);
        }
        printf("\n");
        return 0;
}
