#include <stdio.h>

void main() {
	int age;
	printf("What is your age??");
	scanf_s("%d", &age);

	printf("Your age in years: %d", age);

	int days = (age * 365);

	printf("\nYour age in days: %d", days);
}