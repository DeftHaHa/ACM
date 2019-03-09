#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
        int N;
        int i,j,k;
        char n[105];
        int l;
        int sum;
        int flag;
        memset(n,0,sizeof(n));
        cin>>N;
        while(N--)
        {
                scanf("%s",n);
                l=strlen(n);
                flag=1;
                if(l<3)
                {

                        for(i=0;i<l;i++)
                        {
                                if(n[i]=='0'||n[i]=='8') flag=0;
                        }
                        if(l==2)
                        {
                                if(((n[0]-'0')*10+(n[1]-'0'))%8==0) flag=0;
                        }
                }
                else
                {

                        for(i=0;i<l;i++)
                        {
                                if(n[i]=='0'||n[i]=='8')
                                {
                                        flag=0;
                                        break;
                                }
                        }
                        if(flag)
                        {
                                for(i=l-1;i>=0;i--)
                                {
                                        if(!flag) break;
                                        for(j=i-1;j>=0;j--)
                                        {
                                                if(((n[i]-'0')+(n[j]-'0')*10)%8==0)
                                                {
                                                        flag=0;
                                                        break;
                                                }
                                        }
                                }
                        }
                        if(flag)
                        {
                                for(i=l-1;i>=2;i--)
                                {
                                        if(!flag) break;
                                        for(j=i-1;j>=1;j--)
                                        {
                                                if(!flag) break;
                                                for(k=j-1;k>=0;k--)
                                                {
                                                        if(((n[i]-'0')+(n[j]-'0')*10+(n[k]-'0')*100)%8==0) flag=0;
                                                }
                                        }
                                }
                        }

                }
                if(flag) cout<<"NO\n";
                else cout<<"YES\n";
                memset(n,0,sizeof(0));
        }
        return 0;
}
