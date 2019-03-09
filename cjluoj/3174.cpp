#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        int N;
        string s;
        int ans[5];
        while(cin>>N)
        {
                getline(cin,s);
                while(N--)
                {

                        getline(cin,s);
                        for(int i=0;i<5;i++) ans[i]=0;
                        for(int i=0;i<s.length();i++)
                        {
                                switch(s[i])
                                {
                                     case 'a':ans[0]++;break;
                                     case 'e':ans[1]++;break;
                                     case 'i':ans[2]++;break;
                                     case 'o':ans[3]++;break;
                                     case 'u':ans[4]++;break;
                                }
                        }
                        cout<<ans[0];
                        for(int i=1;i<5;i++) cout<<" "<<ans[i];
                        cout<<endl;
                }

        }

        return 0;
}
