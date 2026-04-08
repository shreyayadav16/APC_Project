#include "inverted.h"

int insert_file(Flist **head, char *fname)
{
    Flist *new = malloc(sizeof(Flist));
    strcpy(new->fname, fname);
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    Flist *temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = new;
    return SUCCESS;
}

void create_database(Flist *fhead, Mlist **mhead)
{
    char word[50];
    Flist *fptr = fhead;

    while (fptr)
    {
        FILE *fp = fopen(fptr->fname, "r");
        if (!fp)
        {
            fptr = fptr->next;
            continue;
        }

        while (fscanf(fp, "%s", word) != EOF)
        {
            for (int i = 0; word[i]; i++)
                word[i] = tolower(word[i]);

            Mlist *mtemp = *mhead, *prev = NULL;
            while (mtemp && strcmp(mtemp->word, word) < 0)
            {
                prev = mtemp;
                mtemp = mtemp->next;
            }

            if (mtemp && strcmp(mtemp->word, word) == 0)
            {
                Slist *stemp = mtemp->slink;
                while (stemp)
                {
                    if (strcmp(stemp->fname, fptr->fname) == 0)
                    {
                        stemp->count++;
                        break;
                    }
                    if (!stemp->next)
                    {
                        Slist *new = malloc(sizeof(Slist));
                        strcpy(new->fname, fptr->fname);
                        new->count = 1;
                        new->next = NULL;
                        stemp->next = new;
                        break;
                    }
                    stemp = stemp->next;
                }
            }
            else
            {
                Mlist *new = malloc(sizeof(Mlist));
                strcpy(new->word, word);
                new->next = mtemp;

                Slist *snew = malloc(sizeof(Slist));
                strcpy(snew->fname, fptr->fname);
                snew->count = 1;
                snew->next = NULL;
                new->slink = snew;

                if (prev)
                    prev->next = new;
                else
                    *mhead = new;
            }
        }
        fclose(fp);
        fptr = fptr->next;
    }
}
