#include<iostream>
using namespace std;
int main()
{
        int  a[2][3]= {{1,2,3},{4,5,6}};
        int  b[3][2]= {{100,10},{10,100},{1,1000}};
        for(int i=0;i<2;i++)
        {
                for(int j=0;j<2;j++)
                {
                        int c=0;
                        for(int k=0;k<3;k++)
                            c+=a[i][k]*b[k][j];
                        cout<<c;
                        if(j<1) cout<<' ';
                }
                cout<<endl;

        }
        return 0;
}
