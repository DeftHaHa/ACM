#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
        int a[1005]={1,7,3,5,9,4,8};
        int n=7;
        int i;
        int maxl=0;
        int ans[1005]={0};
        int j=0;
        int l=0;
        int a_1[1005];
        for(int i=0;i<(1<<n);i++)
        {
                j=0;
                l=0;
                for(int i=0;i<n;i++)
                {
                        if(i&(1<<i))
                        {
                                a_1[j]=a[i];
                                j++;
                                l++;
                                printf("%d",a[i]);
                        }
                }
                if(l>maxl)
                {
                        maxl=l;
                        for(int i=0;i<maxl;i++)
                                ans[i]=a_1[i];
                }                           //i<(1<<n) 生成0~n的二进制序列对应的数值
        }
        printf("%d",maxl);
        for(i=0;i<maxl;i++)
                printf(" %d",ans[i]);
}
