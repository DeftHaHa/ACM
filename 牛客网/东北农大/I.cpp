#include<cstdio>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
//��������:
///��ǰ����x����������ѡ����ĳ����Ʒ�ļ���S����ô���ǵĵ�λ�����ļ�ֵ��   
/// ��k(k��S)vi / ��k(k��S)wi
///��˾ͱ�����ж��Ƿ����S�������������
//��k(k��S)vi / ��k(k��S)wi >=x
//����: ��k(k��S)��vi-x*wi��>=0
///����ÿ��x�� vi-x*wi��С�������� 
#define eps 1e-8  
double w[100005],v[100005];  
double y[100005];    //v-x*w  
double max_ave;  
int n,k; 
bool get(double x)  
{  
    int i;  
    double sum=0;  
    for(i=0;i<n;i++)  
    {  
        y[i]=v[i]-x*w[i];  
    }  
    sort(y,y+n);  
    for(i=0;i<k;i++)  
    {  
        sum+=y[n-i-1];  
    }  
    return sum>=0;
}  
void bin()  
{  
    double low,high,mid;  
    low=0.0;  
    high=0x3f3f3f3f;  
    for(int i=0;i<100;i++)  
    {  
        mid=(low+high)/2;  
        if(get(mid))  
        low=mid;  
        else high=mid;  
    }  
    printf("%.2lf\n",high);  
}  
int main()  
{  
    int T;
    cin>>T;
    while(T--)
    {
		scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)  scanf("%lf%lf",&w[i],&v[i]);  
        bin();
    }     
    return 0;  
}  
