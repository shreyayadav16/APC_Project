#include "header.h"
#include <string.h>

int add_d_list(char *opr1, char *opr2)
{
    int i;

    for (i = strlen(opr1) - 1; i >= 0; i--)
        insert_at_first(&head1, &tail1, opr1[i] - '0');

    for (i = strlen(opr2) - 1; i >= 0; i--)
        insert_at_first(&head2, &tail2, opr2[i] - '0');

    return SUCCESS;
}
