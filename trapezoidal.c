#include<stdio.h>
#include<math.h>

#define f(x) 1/(1+ pow(x,2))

int main() 
{
	float a,b,integral,h,k;
	int subInterval,i;
	
	printf("Enter the lower limit :");
	scanf("%f",&a);
		printf("Enter the upper limit :");
	scanf("%f",&b);
	printf("Enter the number of subIntervals :");
	scanf("%d",&subInterval);
	
	h = (b-a)/subInterval;
	integral= f(a) + f(b);
	for(i=1;i<=subInterval-1;i++)
	{
		k= a + i*h;
		integral = integral + 2*f(k);
	}
	integral =integral * h/2;
	 printf("\nRequired value of integration is: %.3f", integral);
return 0;
}