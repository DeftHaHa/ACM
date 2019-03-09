 #include <iostream>
using namespace std;
int sum (int a,int b) {
    int  x, y;
    x = a | b;
    y = a & b;
    while (y) {
       	x^=y;
        y <<= 1;
        a = x;
        b = y;
        x = a | b;
        y = a & b;
    }
    return x;
}
int main()
{
	for(int i=-10;i<=10;i++)
	{
		for(int j=-10;j<=10;j++)
		{
			if(sum(i,j)!=i+j)
			{
				cout<<i<<'+'<<j<<"!="<<sum(i,j)<<endl;
			}
		}
	}
	return 0;
}

