#include<stdio.h>
#include<string.h>
int main()
{
        char a[5000],a1[5000];
        int a1i=0;
        int i,j;
        int t=0;
        int l[2500],li=0,lt;
        char b[2500][5000];
        int maxi=0;
        memset(l,0,sizeof(l));
        for(i=0;i<5000;i++)
        {
                scanf("%c",a[i]);
                if(a[i]=='\n') break;
                else if(a[i]>=65&&a[i]<=91) a[i]+=32;
                t++;
        }
        for(i=0;i<t;i++)
        {
                if((a[i]>='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9'))
                {
                        a1[a1i]=a[i];
                        a1i++;
                }
        }                                                                  //提取字母和数字
        for(i=0;i<a1i;i++)
        {
                for(j=0;j<a1i;j++)
                {
                        if(a1[i]==a1[j])
                        {
                                if((j-i)%2==0)
                                        lt=1;
                                else
                                        lt=0;
                                while(i>=j)
                                {
                                        b[li][i]=a1[i];
                                        i++;j--;
                                        if(a1[i]!=a1[j]) break;
                                        l[li]+=2;
                                }
                                l[li]-=lt;
                                if(i==j) li++;
                        }
                }
        }                                                                  //判断回文
        if(li!=0)
        {
                for(i=0;i<li;i++)
                {
                        if(l[i]>=l[i+1])
                                maxi=i;
                }
        }
        for(i=0;i<l[maxi]/2;i++)
                printf("%d",b[maxi][i]);
        for(i=l[maxi]-1;i>l[maxi]/2;i--)
                printf("%d",b[maxi][i]);
        return 0;
}
