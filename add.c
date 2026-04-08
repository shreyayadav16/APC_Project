#include "header.h"

int perform_addition(void)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;
    int carry = 0;

    while (temp1 || temp2)
    {
        int d1 = temp1 ? temp1->data : 0;
        int d2 = temp2 ? temp2->data : 0;

        int sum = d1 + d2 + carry;
        carry = sum / 10;
        sum %= 10;

        insert_at_first(&headR, &tailR, sum);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    if (carry)
        insert_at_first(&headR, &tailR, carry);

    printf("Result: ");
    if (sign)
        printf("-");

    print_list(headR);
    return SUCCESS;
}
