#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/* Global doubly linked lists */
Dlist *head1 = NULL, *tail1 = NULL;
Dlist *head2 = NULL, *tail2 = NULL;
Dlist *headR = NULL, *tailR = NULL;

/* Result sign flag
   0 -> positive
   1 -> negative */
int sign = 0;

int main(int argc, char *argv[])
{
    /* Check command line arguments */
    if (argc != 4)
    {
        printf("Usage: ./a.out <num1> <operator> <num2>\n");
        return FAILURE;
    }

    char *opr1 = argv[1];
    char *opr2 = argv[3];
    char op   = argv[2][0];

    /* Validate inputs */
    if (validate_inputs(opr1, opr2, op) == FAILURE)
        return FAILURE;

    printf("Performing: %s %c %s\n", opr1, op, opr2);

    /* Detect operand signs */
    int op1Sign = (*opr1 == '-') ? -1 : 1;
    int op2Sign = (*opr2 == '-') ? -1 : 1;

    /* Ignore sign before storing digits */
    if (*opr1 == '+' || *opr1 == '-') opr1++;
    if (*opr2 == '+' || *opr2 == '-') opr2++;

    /* Reset all lists before operation */
    head1 = tail1 = head2 = tail2 = headR = tailR = NULL;

    /* Store digits of operands into doubly linked lists */
    add_d_list(opr1, opr2);

    switch (op)
    {
        /* ---------------- ADDITION ---------------- */
        case '+':
        {
            if (op1Sign == op2Sign)
            {
                /* Same sign -> direct addition */
                sign = (op1Sign == -1);
                perform_addition();
            }
            else
            {
                /* Different signs -> subtraction */
                int cmp = compare_lists(head1, head2);

                if (cmp >= 0)
                    perform_subtraction(head1, tail1,
                                        head2, tail2,
                                        (op1Sign == -1));
                else
                    perform_subtraction(head2, tail2,
                                        head1, tail1,
                                        (op2Sign == -1));
            }
        }
        break;

        /* ---------------- SUBTRACTION ---------------- */
        case '-':
        {
            if (op1Sign != op2Sign)
            {
                /* a - (-b) OR (-a) - b -> addition */
                sign = (op1Sign == -1);
                perform_addition();
            }
            else
            {
                /* Same signs -> subtraction */
                int cmp = compare_lists(head1, head2);

                if (cmp >= 0)
                    perform_subtraction(head1, tail1,
                                        head2, tail2,
                                        (op1Sign == -1));
                else
                    perform_subtraction(head2, tail2,
                                        head1, tail1,
                                        !(op1Sign == -1));
            }
        }
        break;

        /* ---------------- MULTIPLICATION ---------------- */
        case 'x':
        case '*':
        printf("Multiplication not implemented\n");
        return FAILURE;

        /* ---------------- DIVISION ---------------- */
        case '/':
        {
            int resultSign = (op1Sign != op2Sign);

            perform_division(head1, tail1,
                             head2, tail2);

            /* Remove leading zeros */
            while (headR && headR->data == 0 && headR->next)
                delete_at_first(&headR, &tailR);

            printf("Result: ");
            if (resultSign)
                printf("-");

            print_list(headR);
        }
        break;

        default:
            printf("Error: Unsupported operator\n");
            return FAILURE;
    }

    printf("\nProgram finished ✓\n");
    return SUCCESS;
}
