/*==========================================================================
#    > File Name:     minDistance.c
#    > Version:       v0.0.1
#    > Author:        Jiang Wei
#    > Mail:          jiangwei@pmo.ac.cn 
#    > Created Time:  2015-04-07  05:20:30
----------------------------------------------------------------------------
#    > Description :
#        
----------------------------------------------------------------------------
#    > History :
#
==========================================================================*/

#include<stdio.h>
#include<math.h>
#define EPSILON 0.00001

double GetDistanceSqrD(double a, double b, double c, double x0, double y0, double x)
{
    return (x-x0)*(x-x0)+(a*x*x+b*x+c-y0)*(a*x*x+b*x+c-y0);
}


int main()
{
    int a, b, c, x0, y0;
    while(scanf("%d %d %d %d %d",&a, &b, &c, &x0, &y0)!=EOF)
    {
    if((a<-200 && 2>200) 
        || (b<-200 && b>200)
        || (c<-200 && c>200)
        || (x0<-200 && x0>200)
        || (y0<-200 && y0>200))
    {
        printf("Error parameters.\n");
        continue;
    }
    double l,lm,rm,r,midSub,dl,dr,df=0.0;
    double aD=(double)a,bD=(double)b,cD=(double)c,x0D=(double)x0,y0D=(double)y0;
    double midLine=-0.5*bD/aD;
    printf("%f,%f,%f,%f,%f\n",aD,bD,cD,x0D,y0D);
    if(a==0)
    {
        if(b==0)
        {
            df=(x0-c)*(x0-c);
        }
        else
        {
            df=(y0D-bD*x0D-cD)*(y0D-bD*x0D-cD)/(1+bD*bD);
        }
    }
    else
    {
        if(x0D<midLine)
        {
            x0D=2*midLine-x0D;
        }
        l=midLine,lm=2000,rm=5000,midSub=1.0,r=10000;
        while(midSub>EPSILON)
        {
             dl=GetDistanceSqrD(aD,bD,cD,x0D,y0D,lm);
             dr=GetDistanceSqrD(aD,bD,cD,x0D,y0D,rm);
             if(dl<dr)
             {
                 r=rm;
             }
             else
             {
                 l=lm;                 
             }
             lm=l+(r-l)/3;
             rm=r-(r-l)/3;
             midSub=rm-lm;
        }

        df=dl=GetDistanceSqrD(aD,bD,cD,x0D,y0D,0.5*(lm+rm));
        if((x0-midLine)<EPSILON && (midLine-x0)<EPSILON)
        {
            if(df>GetDistanceSqrD(aD,bD,cD,x0D,y0D,midLine))
            {
                df=GetDistanceSqrD(aD,bD,cD,x0D,y0D,midLine);
            }
        }
    }
    printf("%.3f\n",sqrt(df));
    }
    return 0;
}
