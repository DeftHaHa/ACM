#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
const long long mod=1e9+7;
void getFail(char *P,int *fail,int len)
{
        int match=-1;
        fail[0]=-1;
        for(int i=1;i<=len;++i)
        {
                while(match>=0&&P[match+1]!=P[i])
                {
                        match=fail[match];
                }
                if(P[match+1]==P[i]) match++;
                fail[i]=match;
        }

}
int tot;
int fail[1000005];
void KMP(char *T, char *P,int tlen,int plen) {
        int match=-1;
        for (int i=0;i<tlen; ++i)
        {
                while(match>=0&&P[match+1]!=T[i])
                {
                        match = fail[match];
                }cout<<match<<endl;
                if(P[match+1]==T[i])
                {
                        match++;
                        if (match + 1==plen)
                        {  cout<<match+1<<"Y"<<endl;
                                tot++;
                        }
                }
        }
        return;
}
char a[1000005],b[1000005];
char s1[1000005],s2[1000005];
int main()
{
        int T;
        int i,j;
        scanf("%d",&T);
        while(T--)
        {
                memset(a,0,sizeof(a));
                memset(b,0,sizeof(b));
                scanf("%s%s",a,b);
                int plen=0;
                for(i=strlen(b)-1;i>=0;i--) s2[plen++]=b[i];
                getFail(s2,fail,plen);
                j=0;
                for(i=strlen(a)-1;i>=0;i--) s1[j++]=a[i];
                long long ans=0;
                for(i=1;i<=plen;i++)
                {
                        tot=0;
                        KMP(s1,s2,j,i);
                        cout<<'#'<<i<<' '<<tot<<endl;
                        ans+=i*tot%mod;
                }
                cout<<ans<<endl;
        }
        return 0;
}

