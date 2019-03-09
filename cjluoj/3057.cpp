#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
        map<string,int> m;
        int n;
        string s;
        while(cin>>n)
        {
                if(n==0) break;
                m.clear();
                while(n--)
                {
                        cin>>s;
                        m[s]++;
                }
                string anss;
                int ansn=0;
                for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
                {
                        if(it->second>ansn)
                        {
                                ansn=it->second;
                                anss=it->first;
                        }
                }
                cout<<anss<<' '<<ansn<<endl;
        }
        return 0;
}
