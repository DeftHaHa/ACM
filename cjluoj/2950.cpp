#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        int K,W;
        int w[1005];
        while(cin>>K)
        {
                if(K==0) break;
                cin>>W;
                for(int i=0;i<K;i++)
                        cin>>w[i];
                sort(w,w+K);
                int tail=K-1;
                int ans=0;
                for(int i=0;i<K;i++)
                {
                        for(int j=tail;j>=i;j--)
                        {
                                if(i==j)
                                {
                                        ans++;
                                        break;
                                }
                                if(w[i]+w[j]<=W)
                                {
                                        ans+=tail-j+1;
                                        tail=j-1;
                                        break;
                                }
                        }
                }
                cout<<ans<<endl;
        }
        return 0;
}
