#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 1
#define FAILURE 0

/* File list node */
typedef struct file_node
{
    char fname[50];
    struct file_node *next;
} Flist;

/* File count list */
typedef struct sub_node
{
    char fname[50];
    int count;
    struct sub_node *next;
} Slist;

/* Word list */
typedef struct main_node
{
    char word[50];
    Slist *slink;
    struct main_node *next;
} Mlist;

/* Function declarations */
int insert_file(Flist **, char *);
void create_database(Flist *, Mlist **);
void display_database(Mlist *);
void search_word(Mlist *);
void save_database(Mlist *);

#endif
