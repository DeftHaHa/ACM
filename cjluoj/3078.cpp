#include<iostream>
using namespace std;
int main()
{
        int T;
        int N;
        cin>>T;
        int i;
        int a[1005];
        while(T--)
        {
                cin>>N;
                for(i=0;i<N;i++) cin>>a[i];
                int flag=0;
                if(a[1]>a[0]) flag=1;
                else flag=2;
                for(i=1;i<N-1;i++)
                {
                        if(a[i+1]>a[i]&&flag==2)
                        {
                                flag=0;
                                break;
                        }
                        else if(a[i+1]<a[i]&&flag==1)
                        {
                                flag=0;
                                break;
                        }
                }
                if(flag==0) cout<<"terrible"<<endl;
                else if(flag==1) cout<<"better"<<endl;
                else cout<<"worse"<<endl;

        }
        return 0;
}
