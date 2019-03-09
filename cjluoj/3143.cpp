#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int i=0;
        int n;
        int a[2005];
        while(cin>>n)
        {
                a[++i]=n;
        }
        int len=1;
        int ans[2005];
        ans[1]=a[i];
        for(int j=i-1;j>=1;j--)
        {
                if(a[j]>=ans[len])
                {
                        ans[++len]=a[j];
                }
                else
                {
                        int pos=lower_bound(ans+1,ans+len,a[j])-ans;
                        ans[pos]=a[j];
                }
        }
        cout<<len<<endl;
        return 0;
}
