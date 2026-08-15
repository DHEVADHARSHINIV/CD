#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

FILE *fp;

char delim[14] = {
    ' ', '\t', '\n', ',', ';', '(', ')',
    '{', '}', '[', ']', '#', '<', '>'
};

char oper[7] = {'+', '-', '*', '/', '%', '=', '!'};

char key[21][12] = {
    "int", "float", "char", "double", "bool",
    "void", "extern", "unsigned", "goto",
    "static", "class", "struct", "for", "if",
    "else", "return", "register", "long",
    "while", "do"
};

char predirect[2][12] = {"include", "define"};

char header[6][15] = {
    "stdio.h", "conio.h", "malloc.h",
    "process.h", "string.h", "ctype.h"
};

void skipcomment();
void analyze();
void check(char[]);
int isdelim(char);
int isop(char);

int fop = 0, numflag = 0, f = 0;
char c, ch, sop;

int main()
{
    char fname[50];

    printf("\nEnter filename: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");

    if (fp == NULL)
    {
        printf("\nThe file doesn't exist.\n");
        return 1;
    }

    analyze();

    fclose(fp);

    printf("\nEnd of file\n");

    return 0;
}

void analyze()
{
    char token[50];
    int j = 0;

    while ((c = getc(fp)) != EOF)
    {
        /* Comments */
        if (c == '/')
        {
            skipcomment();
        }

        /* String */
        else if (c == '"')
        {
            while ((c = getc(fp)) != '"' && c != EOF);
        }

        /* Identifier or keyword */
        else if (isalpha(c) || c == '_')
        {
            if (j > 0)
            {
                token[j] = '\0';
                check(token);
                j = 0;
            }

            token[j++] = c;

            while ((c = getc(fp)) != EOF &&
                   (isalnum(c) || c == '_'))
            {
                token[j++] = c;
            }

            token[j] = '\0';
            check(token);
            j = 0;

            if (c != EOF)
                ungetc(c, fp);
        }

        /* Number */
        else if (isdigit(c))
        {
            token[j++] = c;

            while ((c = getc(fp)) != EOF &&
                   (isdigit(c) || c == '.'))
            {
                token[j++] = c;
            }

            token[j] = '\0';

            printf("\nNumber\t\t%s", token);

            j = 0;

            if (c != EOF)
                ungetc(c, fp);
        }

        /* Delimiter */
        else if (isdelim(c))
        {
            printf("\nDelimiter\t%c", c);
        }

        /* Operator */
        else if (isop(c))
        {
            if (fop == 1)
            {
                printf("\nOperator\t%c%c", c, sop);
                fop = 0;
            }
            else
            {
                printf("\nOperator\t%c", c);
            }
        }
    }
}

int isdelim(char c)
{
    int i;

    for (i = 0; i < 14; i++)
    {
        if (c == delim[i])
            return 1;
    }

    return 0;
}

int isop(char c)
{
    int i, j;
    char next;

    for (i = 0; i < 7; i++)
    {
        if (c == oper[i])
        {
            next = getc(fp);

            for (j = 0; j < 7; j++)
            {
                if (next == oper[j])
                {
                    fop = 1;
                    sop = next;
                    return 1;
                }
            }

            ungetc(next, fp);
            return 1;
        }
    }

    return 0;
}

void check(char t[])
{
    int i;

    if (strlen(t) == 0)
        return;

    /* Preprocessor directive */
    for (i = 0; i < 2; i++)
    {
        if (strcmp(t, predirect[i]) == 0)
        {
            printf("\nPreprocessor directive\t%s", t);
            return;
        }
    }

    /* Header file */
    for (i = 0; i < 6; i++)
    {
        if (strcmp(t, header[i]) == 0)
        {
            printf("\nHeader file\t%s", t);
            return;
        }
    }

    /* Keyword */
    for (i = 0; i < 21; i++)
    {
        if (strcmp(key[i], t) == 0)
        {
            printf("\nKeyword\t\t%s", t);
            return;
        }
    }

    /* Identifier */
    printf("\nIdentifier\t%s", t);
}

void skipcomment()
{
    ch = getc(fp);

    /* Single-line comment */
    if (ch == '/')
    {
        while ((ch = getc(fp)) != '\n' && ch != EOF);
    }

    /* Multi-line comment */
    else if (ch == '*')
    {
        while (1)
        {
            ch = getc(fp);

            if (ch == EOF)
                break;

            if (ch == '*')
            {
                c = getc(fp);

                if (c == '/')
                    break;

                ungetc(c, fp);
            }
        }
    }

    /* Normal division operator */
    else
    {
        ungetc(ch, fp);
        printf("\nOperator\t/");
    }
}