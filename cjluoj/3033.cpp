#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int N;
        int m[1005],p[1005];
        int i;
        while(cin>>N)
        {
                for(i=0;i<N;i++) cin>>m[i];
                for(i=0;i<N;i++) cin>>p[i];
                sort(m,m+N);
                sort(p,p+N);
                int ans = 0;
                for(i=0;i<=N;i++)
                {
                        ans+=m[i]*p[N-i-1];
                }
                cout<<ans<<endl;
        }
        return 0;
}
