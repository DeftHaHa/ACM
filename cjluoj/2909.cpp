#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
int main()
{
        map<char,char> res;
        res['A']='A';
        res['E']='3';
        res['H']='H';
        res['I']='I';
        res['J']='L';
        res['L']='J';
        res['M']='M';
        res['O']='O';
        res['S']='2';
        res['T']='T';
        res['U']='U';
        res['V']='V';
        res['W']='W';
        res['X']='X';
        res['Y']='Y';
        res['Z']='5';
        res['1']='1';
        res['2']='S';
        res['3']='E';
        res['5']='Z';
        res['8']='8';
        string s;
        bool flagp,flagm;
        while(cin>>s)
        {
                flagp=flagm=true;
                for(int i=0,j=s.length()-1;i<=j;i++,j--)
                {
                        if(s[i]!=s[j]) flagp=false;
                        if(res.count(s[i]))
                        {
                                if(res[i]==res[j])
                                        continue;
                                else flagm=false;
                        }
                        else flagm=false;
                }
                cout<<s;
                printf(" -- ");
                if(flagp)
                {
                        if(flagm) printf("is a mirrored palindrome.\n");
                        else printf("is a regular palindrome.\n");
                }
                else
                {
                        if(flagm) printf("is a mirrored string.\n");
                        else printf("is not a palindrome.\n");
                }
                cout<<endl;
        }
        return 0;
}
