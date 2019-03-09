#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<char,array<int,100005> > PAIR;
struct cmpv
{
        bool operator() (const PAIR &a,const PAIR &b)
        {
                for(int k=100005;k>=0;k--)
                        if(a.second[k]!=b.second[k])
                                return a.second[k]>b.second[k];
        }
};
map<char,array<int,100005> > m;
int main()
{
        int n,c=1;
        int i,j;
        int t;
        long long change[30];
        long long sum;
        long long mod=1e9+7;
        string s[100005];
        long long x[100005]={1};
        int l;
        for(i=1;i<=100000;i++)
        {
                x[i]=x[i-1]*26%mod;
        }
        while(scanf("%d",&n)!=EOF)
        {
                m.clear();
                for(i=0;i<n;i++)
                {
                        cin>>s[i];
                        l=s[i].size();
                        for(j=0;j<l;j++)
                        {
                                m[s[i][j]][l-j-1]+=1;
                        }
                }
                vector<PAIR> vm(m.begin(),m.end());
                for(j=0;j<vm.size();j++)
                {
                        for(i=0;i<100004;i++)
                        {
                                vm[j].second[i+1]=vm[j].second[i]/26;
                                vm[j].second[i]=vm[j].second[i]%26;
                        }
                }

                sort(vm.begin(),vm.end(),cmpv());
                t=25;
                for(i=0;i<vm.size();i++)
                       change[vm[i].first-'a']=t--;
                sum=0;
                for(i=0;i<n;i++)
                {
                        l=s[i].size()-1;
                        for(j=0;j<l+1;j++)
                        {
                                sum+=(x[l-j]*change[s[i][j]-'a']);
                        }
                        sum%=mod;
                }
                printf("Case #%d: %lld\n",c++,sum);
        }
        return 0;
}
