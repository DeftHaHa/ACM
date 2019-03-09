#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len = s.length();
	if(len <= 20)
	{
		printf("1 %d\n",len);
		cout<<s<<endl;
	}
	else
	{
		if(len%20==0)
		{
			cout<<len/20<<' '<<20<<endl;
			for(int i = 0;i<len/20;i++)
			{
				for(int j = i*20;j<(i+1)*20;j++)
					cout<<s[j];
				cout<<endl;
			}
		}
		else
		{
			int row = len/20+1;
			int n = row*20-len;
			int col;

				col = 20-n/row;
				int AS = row*col - len;
				int as[5];
				memset(as,0,sizeof(as));
				if(AS)
				{
					for(int i = 0;i < row;i++) as[i] = AS/row;
					if(AS%row)
					{
						int la = AS - row*(AS/row);
						for(int i = 0;i<row&&la;i++,la--) as[i]++;
					}
				}
				int tag = 0; 
				cout<<row<<' '<<col<<endl;
				for(int i = 0;i<row;i++)
				{
					for(int j = 0;j<col-as[i];j++)cout<<s[tag++];
					for(int j = 0;j<as[i];j++) cout<<'*';
					cout<<endl;
				}
				
			
		}
	}
	
	return 0;
}
