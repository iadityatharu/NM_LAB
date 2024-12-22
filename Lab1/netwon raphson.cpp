#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Defining the equation to be solved.
 Change this equation to solve another problem. */
#define f(x) (x*x*x - 4*x - 9)
/* Defining the derivative of the equation.
 Change this equation as per the problem. */
#define g(x) (3*x*x - 4)
int main() {
 float x0, x1, f0, g0, e;
 int step = 1;
  printf("Netwon Raphson Method By Aditya Chaudhary\n");

 // Inputs
 up:
 printf("Enter initial guess: ");
 scanf("%f", &x0);
 printf("Enter tolerable error: ");
 scanf("%f", &e);

 // Implementing Newton-Raphson Method
 printf("\nStep\t\tx0\t\tf(x0)\t\tg(x0)\t\tx1\t\tf(x1)\n");
 do {
 g0 = g(x0);
 f0 = f(x0);

 if (g0 == 0.0) {
 printf("Mathematical error: derivative is zero.\n");
 goto up;
 }

 x1 = x0 - f0/g0;
 printf("%d\t\t%f\t%f\t%f\t%f\t%f\n", step, x0, f0, g0, x1, f(x1));

 x0 = x1;
 step += 1;
 } while (fabs(f(x1)) > e);

 printf("\nRoot is: %f\n", x1);
 return 0;
}
