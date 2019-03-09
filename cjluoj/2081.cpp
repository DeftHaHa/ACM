#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
        string s;
        int i,j;
        int ans;
        int temp;
        int k;
        char ch;
        while(getline(cin,s))
        {

                int l=s.size();
                ans=1;
                for(i=1;i<l;i++)
                {
                        temp=1;
                        for(k=1;k<=min(l-i,i);k++)
                        {
                                if(s[i-k]==s[i+k]) temp+=2;
                                else break;
                        }
                        if(temp>ans) ans=temp;
                        int left=i-1,right=i;
                        temp=0;
                        while(left!=-1&&right!=l)
                        {
                                if(s[left]==s[right])
                                {
                                        temp+=2;
                                        left--;
                                        right++;
                                }
                                else break;
                        }
                        if(temp>ans) ans=temp;
                }
                cout<<ans<<endl;
                s.clear();
        }
        return 0;
}
