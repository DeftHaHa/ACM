#include<iostream>
using namespace std;
struct Vec{
	double x,y;
	Vec(double x = 0,double y = 0):x(x),y(y){}
	Vec operator + (Vec v) {return Vec(x+v.x, y+v.y);}
	Vec operator - (Vec v) {return Vec(x-v.x, y-v.y);}
	Vec operator * (double a) {return Vec(a*a, a*y);}
	Vec operator / (double a) {return Vec(x/a, y/a);}
}; 
int main()
{
	return 0;	
} 
