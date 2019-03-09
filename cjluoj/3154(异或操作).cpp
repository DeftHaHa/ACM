#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        int n;
        int a[10005];
        while(scanf("%d",&n)!=EOF)
        {
                for(int i=0;i<n;i++) scanf("%d",&a[i]);
                int i=0;
                int num=0,num1=0;
                int ret = 0;
                int pos = 0;
                int temp = 0;
                for (i = 0; i < n ; i++)
                {
                        ret ^= a[i];
                }
                temp = ret;
                while (ret)
                {
                        if (ret % 2 == 1)
                        {
                              break;
                        }
                        pos++;
                        ret /= 2;
                }
                for (i = 0; i < n ; i++)
                {
                        if ((a[i] >> pos) & 1)
                        {
                             num1^= a [i];
                        }
                }
                printf("%d\n",num1);
        }
        return 0;
}
