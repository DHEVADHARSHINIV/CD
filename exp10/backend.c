#include <stdio.h>
#include <string.h>

int main()
{
    char result[20], op1[20], op2[20], op;

    printf("Enter Three Address Code (Example: t1=a+b)\n");
    scanf("%[^=]=%[^+-*/]%c%s", result, op1, &op, op2);

    printf("\n8086 Assembly Code\n\n");

    printf("MOV AX, %s\n", op1);

    switch(op)
    {
        case '+':
            printf("ADD AX, %s\n", op2);
            break;

        case '-':
            printf("SUB AX, %s\n", op2);
            break;

        case '*':
            printf("MUL %s\n", op2);
            break;

        case '/':
            printf("DIV %s\n", op2);
            break;

        default:
            printf("Invalid Operator\n");
            return 0;
    }

    printf("MOV %s, AX\n", result);

    return 0;
}