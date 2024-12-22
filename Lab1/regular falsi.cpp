#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Defining the equation to be solved. */
#define f(x) (cos(x) - (x) * exp(x))
int main() {
 float x0, x1, x2, f0, f1, f2, e;
 int step = 1;
  printf("Regular Falsi Method By Aditya Chaudhary\n");
 // Inputs
 up:
 printf("Enter two initial guesses: ");
 scanf("%f%f", &x0, &x1);
 printf("Enter tolerable error: ");
 scanf("%f", &e);
 // Calculating functional values
 f0 = f(x0);
 f1 = f(x1);
 // Checking whether the given guesses bracket the root or not
 if (f0 * f1 > 0.0) {
 printf("Incorrect initial guesses. The function values at the guesses must have opposite signs.\n");
 goto up;
 }
 // Implementing Regula Falsi (False Position) Method
 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
 do {
 // Avoid division by zero
 if (f0 == f1) {
 printf("Mathematical error: Division by zero.\n");
 return -1;
 }
 x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
 f2 = f(x2);
 printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);
 if (f0 * f2 < 0) {
 x1 = x2;
 f1 = f2;
 } else {
 x0 = x2;
 f0 = f2;
 }
 step += 1;
 if (fabs(x1 - x0) < e) { // Improved stopping condition
 printf("\nRoot is: %f\n", x2);
 return 0;
 }
 } while (fabs(f2) > e);
 printf("\nRoot is: %f\n", x2);
 return 0;
}
