#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
        long long n;
        long long F[88];
        long long ans;
        F[1]=1;F[2]=2;
        for(int i=3;i<88;i++)
                F[i]=F[i-1]+F[i-2];
        while (cin>>n)
        {
                ans=0;
                if(n==2)
                {
                        cout<<"1"<<endl;
                        continue;
                }
                n-=3;
                ans+=2;
                long long sum=2;
                int i=3;
                while(sum<=n)
                {
                        ans++;
                        sum+=F[i++];
                }
                cout<<ans<<endl;
        }
        return 0;
}
