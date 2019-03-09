#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
struct student
{
        int id;
        string name;
        int age;
}stu[4]={2016001,"Zhang", 19,2016002, "Li",20,2016003,  "wang", 21};
int main()
{
        int id;
        int i;
        while(cin>>id)
        {
                for(i=0;i<3;i++)
                {
                        if(stu[i].id==id)
                        {
                                cout<<id<<' '<<stu[i].name<<' '<<stu[i].age<<endl;
                        }
                }
        }
        return 0;
}
