#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

int main()
{
    FILE* fp=fopen("Mandelbrot.txt","wt");

    if(fp==NULL)
    {
        printf("reset and try again");
        return 1;
    }

    int width,height,i;
    double x,y,a,b,temp,res=256;

    for(height=0; height<=4*res; height++)
    {
        b=2-(height/res);
        for (width = 0; width <=4*res; width++)
        {
            a=-2+(width/res);
            x=0;
            y=0;
            for ( i = 1; i <= NUM; i++)
            {
                temp=x;
                x=(x*x)-(y*y)+a;
                y=(2*temp*y)+b;
                if((x*x)+(y*y)>4)
                    break;
            }
            if(i>=1001)
            {
                //printf(" . ");
                fprintf(fp,"%f %f\n",a,b);
            }
            //else
                //printf(" * ");
            
        }
        //printf("\n");

    }

    fclose(fp);
    return 0;
}