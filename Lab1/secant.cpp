#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Defining the equation to be solved. */
#define f(x) ((x)*(x)*(x) - 4*(x) - 6)
int main() {
 float x0, x1, x2, f0, f1, f2, e;
 int step = 1, N;
  printf("Secant  Method By Aditya Chaudhary\n");
 // Inputs
 up:
 printf("Enter two initial guesses: ");
 scanf("%f%f", &x0, &x1);
 printf("Enter tolerable error: ");
 scanf("%f", &e);
 printf("Enter maximum iterations: ");
 scanf("%d", &N);
 // Implementing Secant Method
 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
 do {
 f0 = f(x0);
 f1 = f(x1);
 // Handle division by zero
 if (f1 - f0 == 0.0) {
 printf("Mathematical error: f(x0) and f(x1) are equal.\n");
 goto up; // Re-prompt for new guesses
 }
 x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
 f2 = f(x2);
 printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);
 // Update values for the next iteration
 x0 = x1;
 x1 = x2;
 step += 1;
 if (step > N) {
 printf("Not Convergent.\n");
 return -1; // Exit with error code
 }
 } while (fabs(f2) > e);
 printf("\nRoot is: %f\n", x2);
 return 0; // Exit successfully
}
