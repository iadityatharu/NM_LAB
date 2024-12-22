#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Define the function f(x) to be solved */
#define f(x) ((x)*(x)*(x)*(x) - (x) - 10)
/* Write f(x) as x = g(x) and define g(x) here */
#define g(x) (pow((x) + 10, 0.25))
int main() {
 int step = 1, N;
 float x0, x1, e;
  printf("Fixed Point Method By Aditya Chaudhary\n");
 // Inputs
 printf("Enter initial guess: ");
 scanf("%f", &x0);
 printf("Enter tolerable error: ");
 scanf("%f", &e);
 printf("Enter maximum iterations: ");
 scanf("%d", &N);
 // Implementing Fixed Point Iteration
 printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
 do {
 x1 = g(x0);
 printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, f(x0), x1, f(x1));
 // Check for convergence
 if (fabs(x1 - x0) < e) {
 printf("\nRoot is: %f\n", x1);
 return 0; // Exit successfully
 }
 x0 = x1;
 step += 1;
 // Check for maximum iterations
 if (step > N) {
 printf("Not Convergent.\n");
 return 0; // Exit with non-convergence message
 }
 } while (1);
 return 0;
}
