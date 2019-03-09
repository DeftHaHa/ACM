#include<stdio.h>
#include<string.h>
int main()
{
        int T;
        char a[10000];
        int i;
        int l;
        int ans;
        scanf("%d",&T);
        while(T--)
        {
                ans=0;
                memset(a,0,sizeof(a));
                scanf("%s",&a);
                l=strlen(a);
                for(i=0;i<=l;i++)
                {
                        if(a[i]=='Q')
                                if(a[i+1]=='A'&&a[i+2]=='Q')
                                {
                                        ans++;
                                        i++;
                                }
                }
                printf("%d\n",ans);
        }
        return 0;
}
