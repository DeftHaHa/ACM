#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        char z[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char a[10];
        char ans[100005];
        int L;
        int i;
        int j;
        int t=0;
        scanf("%d",&L);
        L/=5;
        getchar();
        memset(ans,0,sizeof(ans));
        while(L--)
        {

                j=0;
                for(i=4;i>=0;i--)
                {
                        scanf("%c",&a[i]);
                        if(a[i]>='0'&&a[i]<='9')
                        {
                             j+=1<<i;
                        }
                }
                ans[t++]=z[j];
        }
        printf("%s\n",ans);
        return 0;
}
