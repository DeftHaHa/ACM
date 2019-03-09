#include <iostream>
#include<algorithm>
using namespace std;

int  getmid(int a,int b,int c,int d,int e)
{
    if (a < b) {
        swap(a, b);
    }
    if (c < d) {
        swap(c, d);
    }
    if (a < c) {
        swap(a, c);
        swap(b, d);
    }
    if (b < e) {
        swap(b, e);
    }
    if (b < c) {
        swap(b, c);
        swap(d,e);  //
    }
    if (e > c) {
        swap(e, c);
    }
    return c;
}
int main()
{
	int a[10]={1,2,4,5,6};
	do
	{
		if(getmid(a[0],a[1],a[2],a[3],a[4])!=4) 
		{
			for(int i=0;i<4;i++) cout<<a[i]<<' ';
		cout<< "=="<<getmid(a[0],a[1],a[2],a[3],a[4])<<endl;
		}
		
	}while(next_permutation(a,a+5));
	
}
