#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
        char a[20005]={0};
        char b[20005]={0};
        int s[6];
        int i,j,q,w,e,r,t;
        int l;
        int total;
        int ok;
        while(scanf("%s",a)!=EOF)
        {
                total=0;
                j=0;
                for(i=0;a[i]!='\0';i++)
                {
                        if(a[i]>='A'&&a[i]<='Z') a[i]+=32;
                        if(a[i]=='b'||a[i]=='i'||a[i]=='g'||a[i]=='c'||a[i]=='o'||a[i]=='w') b[j++]=a[i];
                }
                l=j;
                ok=0;
                for(i=l-1;i>=0;i--)
                {
                        if(b[i]=='w')
                        {
                                s[0]=i;
                                for(j=i-1;j>=0;j--)
                                {
                                        if(b[j]=='o')
                                        {
                                                s[1]=j;
                                                for(q=j-1;q>=0;q--)
                                                {
                                                        if(b[q]=='c')
                                                        {
                                                                s[2]=q;
                                                                for(w=q-1;w>=0;w--)
                                                                {
                                                                        if(b[w]=='g')
                                                                        {
                                                                                s[3]=w;
                                                                                for(e=w-1;e>=0;e--)
                                                                                {
                                                                                        if(b[e]=='i')
                                                                                        {
                                                                                                s[4]=e;
                                                                                                for(r=e-1;r>=0;r--)
                                                                                                {
                                                                                                        if(b[r]=='b')
                                                                                                        {
                                                                                                                s[5]=r;
                                                                                                                total++;
                                                                                                                ok=1;
                                                                                                                for(t=0;t<6;t++)
                                                                                                                {
                                                                                                                        b[s[t]]=0;

                                                                                                                }


                                                                                                        }if(ok) break;
                                                                                                }
                                                                                        }if(ok) break;
                                                                                }
                                                                        }if(ok) break;
                                                                }
                                                        }if(ok) break;
                                                }
                                        }if(ok) break;
                                }
                        }
                }
                memset(a,0,sizeof(a));
                memset(b,0,sizeof(b));
                printf("%d\n",total);
        }

        return 0;
}
