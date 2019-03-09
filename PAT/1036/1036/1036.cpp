#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int inf=0x3f3f3f3f,ninf=0xc0c0c0c0;
int main()
{
	int N;
	string name,id;
	char gender;
	int grade;
	string mname,mid,fname,fid;
	int mgrade=inf,fgrade=ninf;
	cin>>N;
	while(N--)
	{
		cin>>name>>gender>>id>>grade;
		if(gender=='M')
		{
			if(grade<mgrade)
			{
				mgrade=grade;
				mname=name;
				mid=id;
			}
		}
		else
		{
			if(grade>fgrade)
			{
				fgrade=grade;
				fname=name;
				fid=id;
			}
		}
	}
	if(mgrade==inf) cout<<fname<<' '<<fid<<endl<<"Absent"<<endl;
	else if(fgrade==ninf) cout<<"Absent"<<endl<<mname<<' '<<mid<<endl;
	else cout<<fname<<' '<<fid<<endl<<mname<<' '<<mid<<endl;
	if(mgrade==inf||fgrade==ninf) cout<<"NA"<<endl;
	else cout<<fgrade-mgrade<<endl;
	return 0;
}