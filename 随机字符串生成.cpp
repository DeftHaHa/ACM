#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	string s;
	int N = 100000;//数据组数 
	int MaxLen = 30;//最大长度 
	
	freopen("ranString.txt","w",stdout);
	
	
	int len = rand()%MaxLen+1;
	s="";
	cout<<len<<endl;
	while(len--)
	{
		char ch = 'a'+ rand()%26;
		s += ch;

	}
	cout<<s<<endl;
	
	return 0;
}
