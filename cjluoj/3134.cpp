#include<iostream>
using namespace std;
int main()
{
        int k;
        while(cin>>k)
        {
                double sum=0;
                for(int i=1;;i++)
                {
                        sum+=1.0/i;
                        if(sum>k)
                        {
                                cout<<i<<endl;
                                break;
                        }
                }
        }
        return 0;
}
