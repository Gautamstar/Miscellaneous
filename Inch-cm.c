#include<stdio.h>
int main()
{
    int bigIfTrue = 0;

    while (bigIfTrue == 0)
    {

        float inch, cm;
        printf("Enter length in Inch: ");
        scanf_s("%f", &inch);
        cm = inch * 2.54;
        printf("Equivalent length in Centimetres = %.2f", cm);

        printf("\nType 0 to continue or anything else to exit =\t");

        scanf_s("%i", &bigIfTrue);

    }
    return 0;
}