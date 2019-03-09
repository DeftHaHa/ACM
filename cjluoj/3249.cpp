#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
        int ans[]={701,1,3,13,75,541,587};
        int T,n;
        while(scanf("%d",&T)!=EOF)
        {
                int c=0;
                while(T--)
                {
                        scanf("%d",&n);
                        printf("Case %d: %d\n",++c,ans[n%7]);
                }
        }
        return 0;
}



#include<cstdio>
#include<iostream>
using namespace std;
const int mod=1024;
int jc[1002];
int C(int a,int b)
{
        if(a>b/2) a=b-a;
        return jc[b]/(jc[b-a]*jc[a])%mod;
}
int main()
{
        int i;
        jc[1]=1;
        for(i=2;i<=1000;i++)
        {
                jc[i]=(jc[i-1]*i);
                if(jc[i]%mod!=0) jc[i]%=mod;
                cout<<i<<' '<<jc[i]<<endl;
        }

        int ans[1002];
        ans[1]=1; cout<<"*"<<C(1,7)<<endl;
        for(i=2;i<=1000;i++)
        {
                ans[i]=1;cout<<"##"<<ans[i-1]<<endl<<ans[i];
                for(int j=1;j<=i-1;j++)
                {
                        ans[i]+=(C(j,i)*ans[i-j])%mod;
                        cout<<"+"<<(C(j,i)*ans[i-j]);
                }cout<<endl;
                ans[i]%=mod;
        }
        int T,n;
        int c=0;
        while(scanf("%d",&T)!=EOF)
        {
                while(T--)
                {
                        scanf("%d",&n);
                        printf("Case %d: %d\n",++c,ans[n]);
                }

        }
        return 0;
}
