#include <iostream>
#include <map>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
        {
                int sum = 0;
                map<char, int> m;
                m.clear();
                int start = 1;
                for (int i = 1;i<=s.length();i++)
                {
                        char c = s[i-1];
                        if (m[c]>=start)
                        {
                            start=m[c] + 1;
                            m[c]=i;

                        }
                        else
                        {
                            m[c]=i;
                            sum=max(sum,i-start+1);
                        }

                }
                cout<<sum<<endl;
        }
        return 0;

}
