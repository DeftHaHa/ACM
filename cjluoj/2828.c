#include<stdio.h>
#include<math.h>
int main()
{
        float x,y,z;
        float s;
        scanf("%f%f%f",&x,&y,&z);
        s=(x+y+z)/2;
        printf("%.4f",sqrt(s*(s-x)*(s-y)*(s-z)));
        return 0;
}
