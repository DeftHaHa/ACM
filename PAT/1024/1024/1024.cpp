#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	string num1,num2,sum;
	int k,tot;
	unsigned int i,j;
	while(cin>>num2>>k)
	{
		bool flag=true;
		for(i=0,j=num2.length()-1;i<j;i++,j--)
		{
			if(num2[i]!=num2[j])
			{
				flag=false;
				break;
			}
		}
		if(num2.length()==1||flag)
		{
			cout<<num2<<endl<<0<<endl;
			continue;
		}
		for(tot=1;tot<=k;tot++)
		{
			num1=num2;
			reverse(num1.begin(),num1.end());
			int x=0;
			sum.clear();
			for(i=0;i<num1.size();i++)
			{
				int t=(num1[i]-'0')+(num2[i]-'0')+x;
				if(t>9) x=1;
				else x=0;
				sum+='0'+t%10;
			}
			if(x==1) sum+='1';
			flag=true;
			for(i=0,j=sum.length()-1;i<j;i++,j--)
			{
				if(sum[i]!=sum[j])
				{
					flag=false;
					break;
				}
			}
			if(flag||tot==k) break;
			num2=sum;
		}
		reverse(sum.begin(),sum.end());
		flag=false;
		for(i=0;i<sum.length();i++)
		{
			if(sum[i]!=0) flag=true;
			if(flag) cout<<sum[i];
		}
		cout<<endl<<tot<<endl;
	}
	return 0;
}