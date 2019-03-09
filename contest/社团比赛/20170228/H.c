#include<stdio.h>
int main()
{
        int T;
        float x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
                if((y1-y2)/(x1-x2)==(y1-y3)/(x1-x3))
                        printf("BQG is so sad!\n");
                else if((y1-y2)/(x1-x2)==(y1-y4)/(x1-x4))
                        printf("BQG is so sad!\n");
                else if((y3-y2)/(x3-x2)==(y3-y1)/(x3-x1))
                        printf("BQG is so sad!\n");
                else if((y3-y2)/(x3-x2)==(y3-y4)/(x3-x4))
                        printf("BQG is so sad!\n");
                else if((x1==x2&&y1==y2)||(x1==x3&&y1==y3)||(x1==x4&&y1==y4)||(x3==x2&&y3==y2)||(x4==x2&&y4==y2)||(x3==x4&&y3==y4))
                        printf("BQG is so sad!\n");
                else
                        printf("BQG is happy!\n");
        }
        return 0;
}
