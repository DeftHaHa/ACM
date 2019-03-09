#include<iostream>
#include<set>
using namespace std;
int main()
{
        set<int>s;
        int n;
        int i;
        int t;
        int d,sum;
        while(cin>>n)
        {
                s.clear();
                for(i=0;i<n;i++)
                {
                        cin>>t;
                        s.insert(t);
                }
                cin>>d;
                sum=s.size();
                int ans=n-sum;
                if(ans>=d) ans=sum;
                else  ans=sum-(d-ans);
                cout<<ans<<endl;
        }
        return 0;
}
