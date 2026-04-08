#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

/* Validate whether a string is a valid number */
static int validate_number(char *s)
{
    int i = 0;

    /* Allow optional sign */
    if (s[i] == '+' || s[i] == '-')
        i++;

    /* String should not end after sign */
    if (s[i] == '\0')
        return FAILURE;

    /* Check remaining characters are digits */
    for (; s[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)s[i]))
            return FAILURE;
    }

    return SUCCESS;
}

/* Validate operator and operands */
int validate_inputs(char *opr1, char *opr2, char op)
{
    /* Operator validation */
    if (!(op == '+' || op == '-' || op == '*' ||
          op == 'x' || op == 'X' || op == '/'))
    {
        printf("Error: Invalid operator! Use +  -  *  x  X  /\n");
        return FAILURE;
    }

    /* Operand 1 validation */
    if (validate_number(opr1) == FAILURE)
    {
        printf("Error: Invalid first operand: %s\n", opr1);
        return FAILURE;
    }

    /* Operand 2 validation */
    if (validate_number(opr2) == FAILURE)
    {
        printf("Error: Invalid second operand: %s\n", opr2);
        return FAILURE;
    }

    /* Division by zero check */
    if (op == '/')
    {
        char *p = opr2;

        /* Skip sign */
        if (*p == '+' || *p == '-')
            p++;

        int all_zero = 1;
        while (*p)
        {
            if (*p != '0')
            {
                all_zero = 0;
                break;
            }
            p++;
        }

        if (all_zero)
        {
            printf("Error: Division by zero is not allowed\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}
