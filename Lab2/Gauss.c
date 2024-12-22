#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 10
int main()
{  
    float a[SIZE][SIZE],x[SIZE],ratio;
    int i,j,k,n;
// inputs 
// 1.Reading number of unknowns
    printf("Enter the number of unknowns: \n");
    scanf("%d",&n);
// 2.Reading augumented matrix
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            printf("Enter element a[%d][%d]= ",i,j);
            scanf("%f",&a[i][j]);
        }
    }
//applying gauss elimination 
    for(i=1;i<=n-1;i++)
    {
        if(a[i][i]==0.0)
        {
            printf("Mathematical Error\n");
            exit(0);
        }
        for(j=i+1;j<=n;j++)
        {
            ratio=a[j][i]/a[i][i];
            for(k=1;k<=n+1;k++)
                a[j][k]=a[j][k]-ratio*a[i][k];
        }
    }
//obataining solution by back substituion
    x[n]=a[n][n+1]/a[n][n];
    for(i=n-1;i>=1;i--)
    {
        x[i]=a[i][n+1];
        for(j=i+1;j<=n;j++)
           {
            x[i]=x[i]-a[i][j]*x[j];
 
           }
        x[i]=x[i]/a[i][i];
    }
//Displaying solution
    printf("Solutions\n");
    for(i=1;i<=n;i++)
    {
        printf("x%d = %.3f\n",i,x[i]);
    }
    
    return 0;
}
