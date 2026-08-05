#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c;

    printf("Enter values of a and b:\n");
    scanf("%d%d", &a, &b);

    // Constant Folding
    c = 10 + 20;
    printf("\nConstant Folding:\n");
    printf("c = 10 + 20  ==>  c = %d\n", c);

    // Algebraic Transformation
    printf("\nAlgebraic Transformation:\n");
    printf("a + 0 = %d\n", a + 0);
    printf("b * 1 = %d\n", b * 1);

    // Strength Reduction
    printf("\nStrength Reduction:\n");
    printf("a * 2 = %d (optimized as a << 1)\n", a << 1);

    return 0;
}