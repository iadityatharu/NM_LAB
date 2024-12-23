#include <stdio.h>

/* Define the function f(x, y) here */
float f(float x, float y) {
    return x + y; // Example: Change this to your required function
}

int main() {
    int i, n;
    float x0, y0, xn, h, k1, k2, yn;

    printf("Enter initial condition\n");
    printf("x0 = ");
    scanf("%f", &x0);

    printf("y0 = ");
    scanf("%f", &y0);

    printf("Enter calculation point xn = ");
    scanf("%f", &xn);

    printf("Enter number of steps: ");
    scanf("%d", &n);

    /* Calculating step size (h) */
    h = (xn - x0) / n;

    /* Runge-Kutta method application */
     printf("\n   x0\t    y0\t\n");
    printf("----------------------------------------\n");
    for (i = 0; i < n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h, y0 + k1);
        //k = (k1 + k2)/2;
        yn = y0 + 0.5 * (k1 + k2);
        printf("%0.4f\t %0.4f\n", x0, y0);
        x0 = x0 + h;
        y0 = yn;
    }

    /* Displaying result */
    printf("\nThe value of y at x = %0.2f is %0.4f\n", xn, yn);

    return 0;
}
