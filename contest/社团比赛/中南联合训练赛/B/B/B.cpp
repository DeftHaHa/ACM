#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void conversion(string s1,string &s2,int d1,int d2)
{
    int i,t,num;
    num=0;
    for(i=0;i<s1.size();i++)
	{
        if(s1[i]>='0'&&s1[i]<='9')
		{
            t=s1[i]-'0';
        }
        else t=s1[i]-'A'+10;
        num=num*d1+t;
     }
    i=0;
    s2="";
    while(1)
	{
        t=num%d2;
        num/=d2;
        if(t<=9) s2+=(char)('0'+t);
        else s2+=(char)((t-10+'A'));
        if(num==0)break;
    }

}
int main(){

    string str1, str2;
    int d1, d2;
    while(cin>>str1>>d1>>d2)
	{

        conversion(str1,str2,d1,d2);
		if(str2.length()>7) cout<<"  ERROR"<<endl;
        else
		{
			for(int i=0;i<7-str2.length();i++) cout<<' ';
			reverse(str2.begin(),str2.end());
			cout<<str2<<endl;
		}
    }
    return 0;
}