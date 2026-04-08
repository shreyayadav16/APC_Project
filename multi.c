#include "header.h"

/* Multiply two numbers stored in DLLs */
int mul_d_list(char *opr1, char *opr2)
{
    Dlist *p2 = tail2;
    int shift = 0;

    while (p2)
    {
        Dlist *p1 = tail1;
        int carry = 0;

        /* temporary list for partial result */
        Dlist *tempH = NULL, *tempT = NULL;

        /* add zero shift */
        for (int i = 0; i < shift; i++)
            insert_at_last(&tempH, &tempT, 0);

        while (p1 || carry)
        {
            int mul = carry;

            if (p1)
            {
                mul += p1->data * p2->data;
                p1 = p1->prev;
            }

            insert_at_last(&tempH, &tempT, mul % 10);
            carry = mul / 10;
        }

        /* add partial result to final result */
        Dlist *oldH = headR;
        Dlist *oldT = tailR;

        headR = tailR = NULL;
        head1 = oldH;
        tail1 = oldT;
        head2 = tempH;
        tail2 = tempT;

        perform_addition();

        p2 = p2->prev;
        shift++;
    }

    return SUCCESS;
}
