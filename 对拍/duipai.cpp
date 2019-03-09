#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{   long s,t;
    while(1){
        system("cls");
        do{
            system("data.exe > data.txt"); //data.exe???????
            s=clock();
            system("test.exe < data.txt > try2.out");  //test.exe?????????
            t=clock();
            system("ans.exe < data.txt > try1.out");  //AC.exe??????
            if(system("fc try1.out try2.out > nul")) break;
            else printf("AC time: %ldms\n",t-s); //???????
        }while(1);
        printf("WA time: %ldms\n",t-s);  //????
        system("fc try1.out try2.out");
        system("pause>nul");
    }
    return 0;
}
 

