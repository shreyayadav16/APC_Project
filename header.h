#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

/* Status macros */
#define SUCCESS 0
#define FAILURE -1

/* Doubly linked list node */
typedef struct dlist
{
    int data;
    struct dlist *prev;
    struct dlist *next;
} Dlist;

/* Global lists (defined in main.c) */
extern Dlist *head1, *tail1;
extern Dlist *head2, *tail2;
extern Dlist *headR, *tailR;

/* Global sign flag */
extern int sign;

/* Validation */
int validate_inputs(char *opr1, char *opr2, char op);

/* List creation */
int add_d_list(char *opr1, char *opr2);

/* DLL operations */
int insert_at_first(Dlist **head, Dlist **tail, int data);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int delete_at_first(Dlist **head, Dlist **tail);

/* Arithmetic operations */
int perform_addition(void);
int perform_subtraction(Dlist *h1, Dlist *t1,
                        Dlist *h2, Dlist *t2,
                        int isNegative);
int perform_division(Dlist *h1, Dlist *t1,
                     Dlist *h2, Dlist *t2);

/* Utility */
int compare_lists(Dlist *h1, Dlist *h2);
void print_list(Dlist *head);

#endif
