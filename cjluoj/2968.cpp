#include<iostream>
using namespace std;
int main()
{
        int N;
        int a[55];
        while(cin>>N)
        {
                int ans=0;
                int sum=0,ave;
                for(int i=0;i<N;i++)
                {
                        cin>>a[i];
                        sum+=a[i];
                }
                ave=sum/N;
                for(int i=0;i<N;i++)
                {
                        if(a[i]==ave) continue;
                        ans++;
                        a[i+1]+=a[i]-ave;
                        a[i]=ave;
                }
                cout<<ans<<endl;
        }
        return 0;
}
