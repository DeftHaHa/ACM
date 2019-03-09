#include<cstdio>
using namespace std;
int main()
{
        int n;
        char s[20]={'\0'};
        int i;
        char ch;
        scanf("%d%*c",&n);
        while(n--)
        {
                for(i=0;i<18;i++)
                {
                        scanf("%c",&s[i]);
                }
                ch=getchar();
                printf("He/She is from ");
                if(s[0] == '3' && s[1] == '3')
                        printf("Zhejiang");
                else if(s[0] == '1' && s[1] == '1')
                        printf("Beijing");
                else if(s[0] == '7' && s[1] == '1')
                        printf("Taiwan");
                else if(s[0] == '8' && s[1] == '1')
                        printf("Hong Kong");
                else if(s[0] == '8' && s[1] == '2')
                        printf("Macao");
                else if(s[0] == '2' && s[1] == '1')
                        printf("Liaoning");
                else if(s[0] == '5' && s[1] == '4')
                        printf("Tibet");
                else if(s[0] == '3' && s[1] == '1')
                        printf("Shanghai");
                printf(",and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",s[10],s[11],s[12],s[13],s[6],s[7],s[8],s[9]);
        }
        return 0;
}
