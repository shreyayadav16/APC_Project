#include "header.h"

/* insert at first */
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new) return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;
    return SUCCESS;
}

/* insert at last */
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new) return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
    return SUCCESS;
}

/* delete at first */
int delete_at_first(Dlist **head, Dlist **tail)
{
    if (!*head) return FAILURE;

    Dlist *temp = *head;
    *head = temp->next;

    if (*head)
        (*head)->prev = NULL;
    else
        *tail = NULL;

    free(temp);
    return SUCCESS;
}

/* compare two numbers */
int compare_lists(Dlist *h1, Dlist *h2)
{
    int c1 = 0, c2 = 0;
    Dlist *t1 = h1, *t2 = h2;

    while (t1) { c1++; t1 = t1->next; }
    while (t2) { c2++; t2 = t2->next; }

    if (c1 > c2) return 1;
    if (c1 < c2) return -1;

    while (h1 && h2)
    {
        if (h1->data > h2->data) return 1;
        if (h1->data < h2->data) return -1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return 0;
}

/* print list */
void print_list(Dlist *head)
{
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}
