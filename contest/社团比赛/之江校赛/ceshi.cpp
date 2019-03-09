#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    clock_t start,finish;
    start=clock();

    cout << "HW .... " << endl;

    finish=clock();

    cout <<double( finish-start )/CLOCKS_PER_SEC << " (s) "<< endl;

    return 0;
}
