#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
long long quickpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1) ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
int main()
{
	string s1,s2;
	long long tag,r;
	while(cin>>s1>>s2>>tag>>r)
	{
		if(tag==2) swap(s1,s2);
		long long sum1=0,sum2=0;
		int l1=s1.length(),l2=s2.length();
		int num1[15],num2[15];
		int t=0;
		int maxnum1=0;
		for(int i=l1-1;i>=0;i--)
		{
			if(s1[i]>='a'&&s1[i]<='z')
				num1[t++]=s1[i]-'a'+10;
			else num1[t++]=s1[i]-'0';
			if(num1[t-1]>maxnum1) maxnum1=num1[t-1];
		}
		for(int i=0;i<l1;i++)
		{
			sum1+=quickpow(r,i)*num1[i];
		}
		t=0;
		int maxnum2=0;
		for(int i=l2-1;i>=0;i--)
		{
			if(s2[i]>='a'&&s2[i]<='z')
				num2[t++]=s2[i]-'a'+10;
			else num2[t++]=s2[i]-'0';
			if(num2[t-1]>maxnum2) maxnum2=num2[i];
		}
		bool flag=false;
		for(int i=maxnum2+1;i<36;i++)
		{
			sum2=0;
			for(int j=0;j<l2;j++)
			{
				sum2+=num2[j]*quickpow(i,j);
			}
			if(sum2==sum1)
			{
				cout<<i<<endl;
				flag=true;
				break;
			}
			else if(sum2>sum1) break;
		}
		if(!flag) cout<<"impossible"<<endl;
	}
	return 0;
}
