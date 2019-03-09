#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool prim[100005];
int main()
{
        memset(prim,true,sizeof(prim));
        prim[0]=prim[1]=false;
        for(int i=2;i<=sqrt(100000);i++)
        {
                if(prim[i])
                {
                        for(int j=i*i;j<=100000;j+=i)
                                prim[j]=false;
                }
        }
        int a,b;
        while(cin>>a>>b)
        {
                if(a<b) swap(a,b);
                int ans=a;
                int tot=0;
                for(int i=2;i<=a;i++)
                {
                        if(i!=b&&prim[i]) tot++;
                }
                ans+=tot*(b-1);
                cout<<ans<<endl;
        }
        return 0;
}
