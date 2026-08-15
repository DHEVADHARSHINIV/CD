#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table
{
    char var[10];
    int value;
};

struct table tbl[20];

int n = 0;

void create();
void insert();
void modify();
int search(char variable[], int n);
void display();

int main()
{
    int ch;
    int result;
    char v[10];

    while(1)
    {
        printf("\nEnter your choice\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Modify\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        fflush(stdout);

        if(scanf("%d", &ch) != 1)
        {
            printf("\nInvalid input. Program stopped.\n");
            return 0;
        }

        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                insert();
                break;

            case 3:
                modify();
                break;

            case 4:
                printf("Enter the variable to be searched for: ");
                scanf("%9s", v);

                result = search(v, n);

                if(result == 0)
                    printf("The variable does not belong to the table\n");
                else
                    printf("The location of the variable is %d\n"
                           "The value of %s is %d\n",
                           result,
                           tbl[result].var,
                           tbl[result].value);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

void create()
{
    int i, j;

    printf("Enter the no. of entries: ");
    fflush(stdout);

    if(scanf("%d", &n) != 1)
    {
        printf("Invalid number of entries.\n");
        exit(0);
    }

    if(n < 1 || n > 19)
    {
        printf("Enter number between 1 and 19.\n");
        n = 0;
        return;
    }

    printf("Enter the variable and the value:\n");

    for(i = 1; i <= n; i++)
    {
        scanf("%9s %d", tbl[i].var, &tbl[i].value);

        while(tbl[i].var[0] >= '0' &&
              tbl[i].var[0] <= '9')
        {
            printf("The variable should start with an alphabet\n");
            printf("Enter correct variable name:\n");
            scanf("%9s %d", tbl[i].var, &tbl[i].value);
        }

        for(j = 1; j < i; j++)
        {
            if(strcmp(tbl[i].var, tbl[j].var) == 0)
            {
                printf("The variable already exists.\n");
                printf("Enter another variable and value:\n");

                scanf("%9s %d",
                      tbl[i].var,
                      &tbl[i].value);

                j = 0;
            }
        }
    }

    printf("\nThe table after creation is:\n");
    display();
}

void insert()
{
    int j;

    if(n >= 19)
    {
        printf("Cannot insert. Table is full.\n");
        return;
    }

    n++;

    printf("Enter the variable and the value: ");
    scanf("%9s %d", tbl[n].var, &tbl[n].value);

    while(tbl[n].var[0] >= '0' &&
          tbl[n].var[0] <= '9')
    {
        printf("The variable should start with an alphabet\n");
        printf("Enter correct variable name:\n");

        scanf("%9s %d",
              tbl[n].var,
              &tbl[n].value);
    }

    for(j = 1; j < n; j++)
    {
        if(strcmp(tbl[j].var, tbl[n].var) == 0)
        {
            printf("The variable already exists.\n");
            printf("Enter another variable and value:\n");

            scanf("%9s %d",
                  tbl[n].var,
                  &tbl[n].value);

            j = 0;
        }
    }

    printf("\nThe table after insertion is:\n");
    display();
}

void modify()
{
    char variable[10];
    int result;

    printf("Enter the variable to be modified: ");
    scanf("%9s", variable);

    result = search(variable, n);

    if(result == 0)
    {
        printf("%s does not belong to table\n", variable);
    }
    else
    {
        printf("The current value of %s is %d\n",
               tbl[result].var,
               tbl[result].value);

        printf("Enter the new variable and its value: ");
        scanf("%9s %d",
              tbl[result].var,
              &tbl[result].value);
    }

    printf("\nThe table after modification is:\n");
    display();
}

int search(char variable[], int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        if(strcmp(tbl[i].var, variable) == 0)
            return i;
    }

    return 0;
}

void display()
{
    int i;

    printf("VARIABLE\tVALUE\n");

    for(i = 1; i <= n; i++)
    {
        printf("%s\t\t%d\n",
               tbl[i].var,
               tbl[i].value);
    }
}
