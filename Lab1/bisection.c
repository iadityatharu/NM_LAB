#include<stdio.h>
#include<math.h>
// Defining equation to be solved.
// change the equation to solve another problem.
#define f(x) cos(x)-x*exp(x)
void main()
{
    float x0,x1,x2,f0,f1,f2,e;
    int step=1;
    printf("Bisection Method By Aditya Chaudhary\n");
    
    // Inputs
    up:
    printf("\nEnter initial guess for x:\n");
    scanf("%f%f",&x0,&x1);
    printf("\nEnter desired precision:\n");
    scanf("%f",&e);
    // calculating functional value
    f0=f(x0);
    f1=f(x1);
    // checking whether given guesses brackets the root or  not
    if(f0*f1>0.0){
        printf("Incorrect initial guesses.\n");
        goto up;
    }
    // implementing bisection method 
    printf("\nstep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do{
        x2=(x0+x1)/2;
        f2=f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,x1,x2,f2);
        if (f0*f2<0)
        {
            x1=x2;
            f1=f2;

        }else{
            x0=x2;
            f0=f2;
        }
        step++;

    }while(fabs(f2)>e);
    printf("\n Root is %f,x2");
    
    
}
