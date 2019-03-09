#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
        int N;
        char a[505]={'\0'};
        int i;
        scanf("%d",&N);
        while(N--)
        {
                scanf("%s",a);
                for(i=0;a[i]!='\0';i++)
                {
                        if(a[i]=='0') printf("1");
                        else printf("%c",a[i]);
                }
                printf("\n");
                memset(a,0,sizeof(a));
        }
}
