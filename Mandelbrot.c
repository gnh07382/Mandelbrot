#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv)
{
    if(argc!=6)
        exit(EXIT_FAILURE);

    const double minX = atof(argv[1]), minY = atof(argv[2]), maxX = atof(argv[3]), maxY = atof(argv[4]);
    int resX=atoi(argv[5]), resY=resX*(maxY-minY)/(maxX-minY);
    const int num;

    double x,y;
    double kx=(maxX-minX)/resX;
    double ky=(maxY-minY)/resY;
    int t,k;//k=¼ö·Å °Ë»ç±â

    FILE* fp= fopen("Mandelbrot_set.ppm","wt");

    if(fp==NULL)
        printf("ERROR");

    fprintf(fp,"p6\n"); //magic number
    fprintf(fp,"%d %d\n",resX,resY);
    fprintf(fp,"255\n");

    for (int i = 0; i < resY; i++)
    {
        y=minY+i/ky;
        for (int j = 0; j < resX; j++)
        {
            x=minX+j/kx;

            for (k = 0; k < num&&(x*x)+(y*y)<2; k++)
            {
                t=x;
                x=(x*x)-(y*y)+x;
                y=2*t*y+y;
            }
            if(k>=num)
            {
                char black[]={0,0,0,0,0,0};
                fwrite(black,6,1,fp);
            }
            else
            {
                char color[6];
                color[0] = k >> 8;
                color[1] = k & 255;
                color[2] = k >> 8;
                color[3] = k & 255;
                color[4] = k >> 8;
                color[5] = k & 255;
                fwrite(color, 6, 1, fp);
            }
        }
        
    }

    return 0;
}