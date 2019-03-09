#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n[10005],m[10005];
int sqn[5005],sqm[5005]; //开方
int nlen,mlen;
bool cmp(int a[],int lena,int b[],int lenb)
{
	if(lena!=lenb) return lena>lenb;
	else
	{
		for(int i=lena-1;i>=0;i--)
		{
			if(a[i]!=b[i])
			{
				return a[i]>b[i];
			}
		}
		return false;
	}
}
int t[10005];
int take(int a[],int lena,int b[],int lenb)   //高精度乘法 
{
	memset(t,0,sizeof(t));
	for(int i=0;i<lena;i++)
	{
		for(int j=0;j<lenb;j++)
		{
			t[i+j]+=a[i]*b[j];
		}
	}
	for(int i=0;i<lena+lenb+1;i++)
	{
		if(t[i]>=10)
		{
			t[i+1]+=t[i]/10;
			t[i]%=10;
		}
	}
	for(int i=lena+lenb;i>=0;i--)
	{
		if(t[i]!=0) return i+1;
	}
	return 0;
}
int sqf(int a[],int ans[],int alen)  //高精度开方 
{
	int anslen=(alen+1)/2;
	memset(ans,0,sizeof(ans));
	for(int i=anslen-1;i>=0;i--)
	{
		for(int num=1;num<10;num++)
		{
			ans[i]=num;
			int sqlen=take(ans,anslen,ans,anslen);
			//for(int j=sqlen-1;j>=0;j--) cout<<t[j];cout<<'=';
			//for(int j=anslen-1;j>=0;j--) cout<<ans[j];cout<<endl;
			if(cmp(t,sqlen,a,alen))
			{
				ans[i]--;
				break;
			}
		}
	}
	return anslen;
} 
int main()
{
	///完全平方数有奇数个因数，其他都有偶数个 
	string l,c;
	cin>>l>>c;
	nlen=l.size(),mlen=c.size();
	for(int i=nlen-1;i>=0;i--) n[nlen-i-1]=l[i]-'0';
	for(int i=mlen-1;i>=0;i--) m[nlen-i-1]=c[i]-'0';  //倒置
	if((nlen==1&&n[0]==0)||(m[0]==0&&mlen==0) )cout<<0<<endl;
	else
	{
		int sqnlen=sqf(n,sqn,nlen);
		int sqmlen=sqf(m,sqm,mlen);
		int ANSlen=take(sqn,sqnlen,sqm,sqmlen);
		for(int i=ANSlen-1;i>=0;i--) printf("%d",t[i]);
		cout<<endl;
	}

	return 0;
}
