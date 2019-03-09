#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
        string s;
        int left,right;
        int T,n;
        char ch;
        cin>>T;
        while(T--)
        {
                cin>>n;
                ch=getchar();
                while(n--)
                {
                        s.clear();
                        getline(cin,s);
                        s+='\n';
                        left=0;
                        for(int i=0;i<s.size();i++)
                        {
                                if(s[i]==' '||s[i]=='\n')
                                {
                                        right=i-1;
                                        while(right>=left)
                                        {
                                                swap(s[right],s[left]);
                                                left++;
                                                right--;
                                        }
                                        left=i+1;
                                }
                        }
                        cout<<s;
                }

        }
        return 0;
}


