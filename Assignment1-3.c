#include <stdio.h>


void main() {
	float a, b;
	printf("Enter first float - ");
	scanf_s("%f", &a);

	printf("Enter second float - ");
	scanf_s("%f", &b);

	float sum = a + b;
	float product = a * b;
	float quotient = a / b;

	printf("The two floats are, %f and %f.", a, b);
	printf("\nThe sum = %f", sum);
	printf("\nThe product = %f", product);
	printf("\nThe quotient = %f", quotient);
}