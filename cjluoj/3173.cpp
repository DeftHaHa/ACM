#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int N;
        int n;
        int a[100005];
        while(cin>>N)
        {
                if(N==0) break;
                for(int i=0;i<N;i++) cin>>a[i];
                sort(a,a+N);
                int ans=0;
                for(int i=1;i<N;i++)
                {
                        a[i]+=a[i-1];
                        ans+=a[i];
                        sort(a+i,a+N);
                }
                cout<<ans<<endl;
        }
        return 0;
}
