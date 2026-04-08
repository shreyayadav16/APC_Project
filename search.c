#include "inverted.h"

void display_database(Mlist *head)
{
    while (head)
    {
        printf("\n%s : ", head->word);
        Slist *stemp = head->slink;
        while (stemp)
        {
            printf("%s(%d) ", stemp->fname, stemp->count);
            stemp = stemp->next;
        }
        head = head->next;
    }
    printf("\n");
}

void search_word(Mlist *head)
{
    char key[50];
    printf("Enter word to search: ");
    scanf("%s", key);

    while (head)
    {
        if (strcmp(head->word, key) == 0)
        {
            printf("Word found in:\n");
            Slist *stemp = head->slink;
            while (stemp)
            {
                printf("%s -> %d times\n", stemp->fname, stemp->count);
                stemp = stemp->next;
            }
            return;
        }
        head = head->next;
    }
    printf("Word not found\n");
}

void save_database(Mlist *head)
{
    FILE *fp = fopen("database.txt", "w");
    while (head)
    {
        fprintf(fp, "%s ", head->word);
        Slist *stemp = head->slink;
        while (stemp)
        {
            fprintf(fp, "%s(%d) ", stemp->fname, stemp->count);
            stemp = stemp->next;
        }
        fprintf(fp, "\n");
        head = head->next;
    }
    fclose(fp);
    printf("Database saved to database.txt\n");
}
