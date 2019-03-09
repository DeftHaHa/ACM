#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
        int ans;
        int T;
        int N;
        int i;
        int t,temp;
        while(scanf("%d",&T)!=EOF)
        {
                if(T==0) break;
                while(T--)
                {
                        ans=0;
                        scanf("%d",&N);
                        if(N>=55) i=N-54;
                        else i=1;
                        for(;i<=N;i++)
                        {
                                temp=i;
                                t=i;
                                while(t>0)
                                {
                                       temp+=t%10;
                                       t/=10;
                                }
                                if(temp==N)
                                {
                                        ans=i;
                                        break;
                                }
                        }
                        printf("%d\n",ans);

                }
        }
        return 0;
}
