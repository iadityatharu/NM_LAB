
//lagrange method
#include<stdio.h>
int main()
{
    float x[100],y[100],xp,yp=0,p;
   int i, j,n;
   printf("Enter the number of the data points\n");
   scanf("%d",&n);
   printf("Enter the data points\n");
   for(i=1;i<=n;i++)
   {
    printf("x[%d]=",i);
    scanf("%f",&x[i]);
    printf("y[%d]=",i);
    scanf("%f",&y[i]);
   }
   printf("Enter the interpolations points\n");
   scanf("%f",&xp);

   for(i=1;i<=n;i++)
   {
    p=1;
    for(j=1;j<=n;j++)
    {    if(i!=j)
    {
        p=p*(xp-x[j])/(x[i]-x[j]);
    }

    }
    yp=yp+p*y[i];
   }
   printf("The interpolation value of %.3f is %.3f",xp,yp);

}