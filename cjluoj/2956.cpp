#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
        char s[1005];
        int A,B;
        int a[35],b[35],c[35];
        int T;
        cin>>T;
        while(T--)
        {
                scanf("%d%s%d",&A,s,&B);
                int sy=strlen(s)+1;
                int tota=0,totb=0;
                memset(a,0,sizeof(a));
                memset(b,0,sizeof(b));
                while(A)
                {
                        a[tota++]=A%sy;
                        A/=sy;
                }
                while(B)
                {
                        b[totb++]=B%sy;
                        B/=sy;
                }
                int tot=max(tota,totb);
                for(int i=0;i<tot;i++)
                {
                        c[i]=(a[i]+b[i])%sy;
                }
                int ans=0,t=1;
                for(int i=0;i<tot;i++)
                {
                        ans+=t*c[i];
                        t*=sy;
                }
                cout<<ans<<endl;
        }
        return 0;
}
