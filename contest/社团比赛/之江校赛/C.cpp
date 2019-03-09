#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
int main()
{
        char a[55],b[55];
        char weiji[27][27];
        int i,j;
        int l_a,l_b;
        for(i=1;i<=26;i++)
        {
                for(j=1;j<=26;j++)
                {
                        weiji[i][j]='a'+(i+j-2)%26;
                }
        }
        while(scanf("%s%s",a,b)!=EOF)
        {
                l_a=strlen(a);
                l_b=strlen(b);
                for(i=0;i<l_a;i++)
                {
                        if(a[i]>='a'&&a[i]<='z')
                        {
                                a[i]=weiji[b[i%l_b]-'a'+1][a[i]-'a'+1];
                        }
                }
                printf("%s\n",a);
        }
        return 0;
}
