#include<cstdio>
#include<cstring>
int main()
{
        char ge[9][5]={{'I',0},{'I','I',0},{'I','I','I',0},{'V','I',0},{'V',0},{'I','V',0},{'I','I','V',0},{'I','I','I','V',0},{'X','I',0}};
        char shi[9][5]={{'X',0},{'X','X',0},{'X','X','X',0},{'L','X',0},{'L',0},{'X','L',0},{'X','X','L',0},{'X','X','X','L',0},{'C','X',0}};
        char bai[9][5]={{'C',0},{'C','C',0},{'C','C','C',0},{'D','C',0},{'D',0},{'C','D',0},{'C','C','D',0},{'C','C','C','D',0},{'M','C',0}};
        char qian[3][5]={{'M',0},{'M','M',0},{'M','M','M',0}};
        int n,m;
        int l;
        int w;
        char ans[100];
        while(scanf("%d",&n)!=EOF)
        {
                w=1;
                memset(ans,0,sizeof(ans));
                while(n>0)
                {
                        m=n%10;
                        if(m!=0)
                        {
                                if(w==1)        strcat(ans,&ge[m-1][0]);
                                else if(w==2)   strcat(ans,&shi[m-1][0]);
                                else if(w==3)   strcat(ans,&bai[m-1][0]);
                                else if(w==4)   strcat(ans,&qian[m-1][0]);
                        }
                        n/=10;
                        w++;
                }
                l=strlen(ans);
                for(int i=l-1;i>=0;i--)
                        printf("%c",ans[i]);
                printf("\n");
        }
        return 0;
}
