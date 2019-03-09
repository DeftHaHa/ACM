#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
        int left,right;
        int l;
        int l_b,l_c;
        char a[405]={0};
        int sum=0;
        char b[405]={0};
        int c[405]={0};
        int d[405]={0};
        int ans[405]={0};
        int i,j,k;
        scanf("%s%d",a,&k);
        l=strlen(a);
        if(k==l) k-=1;
        else if(k==0)
        {
                printf("%s\n",a);
                return 0;
        }
        left=0;
        right=l-1;
        while(k--)
        {
                if(a[left]<=a[left+1])
                {
                        sum+=(a[left]-'0');
                        left++;
                }
                else
                {
                        sum+=(a[right]-'0');
                        right--;
                }
        }
        a[++right]=0;
        strcpy(b,a+left);
        l_b=right-left;
        for(i=0;sum>0;i++)
        {
                c[i]=sum%10;
                sum/=10;
        }
        l_c=i;
        for(i=0;i<l_b;i++)      d[i]=b[l_b-i-1]-'0';
        int s,flag=0;


        for(i=0;i<405;i++)
        {
                s=ans[i]+c[i]+d[i];
                ans[i]=s%10;
                ans[i+1]+=s/10;
        }
        for(i=404;i>=0;i--)
                if(ans[i]!=0)  break;
        for(j=i;j>=0;j--)
        {
                printf("%d",ans[j]);
        }
        printf("\n");
        return 0;
}
