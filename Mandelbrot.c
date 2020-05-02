#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

int main()
{
    FILE* fp=fopen("Mandelbrot.txt","wt");//for GNUPlot

    if(fp==NULL)
    {
        printf("reset and try again");
        return 1;
    }

    FILE* fp2=fopen("Mandelbrot.ppm","wt");//for PPM Image (quite strange now I don`t know how to fix this maybe linear transformation)

    if(fp2==NULL)
    {
        printf("reset and try again");
        return 1;
    }

    fprintf(fp2,"P3\n");
    fprintf(fp2,"1024 1024 256\n");      //change if you want(res*4)

    int k=255, m=0;

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
                x=(x*x)-(y*y)+a;                      //complex number multiplication
                y=(2*temp*y)+b;                       
                if((x*x)+(y*y)>4)                     //diverge
                    break;
            }
            if(i>=1001)
            {
                //printf(" . ");                        //enable if you want console outuput
                //fprintf(fp,"%f %f\n",a,b);            //enable if you want to plot in GNUPlot
                fprintf(fp2,"%3d %3d %3d ",m,m,m);
            }
            else
            {
                fprintf(fp2,"%3d %3d %3d ",k,k,k);
                //printf(" * ");
            }

        }
        //printf("\n");
        fprintf(fp2,"\n");

    }

    fclose(fp);
    return 0;
}