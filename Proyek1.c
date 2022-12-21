#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void batak();
void english();
void input();

int main()
{
    do
    {
        printf("\n++++++++++++++ Options ++++++++++++++\n");
        printf("+ 1. Bahasa Inggris - Bahasa Batak  +\n");
        printf("+ 2. Bahasa Batak - Bahasa Inggris  +\n");
        printf("+ 3. Add New Word                   +\n");
        printf("+++++++++++++++++++++++++++++++++++++\n");
        printf("Enter your option : ");

        int opt;
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            batak();
            break;

        case 2:
            english();
            break;

        case 3:
            input();
            break;

        default:
            printf("Invalid options");
            break;
        }
    } while (0);

    return 0;
}

void batak()
{
    char *filename = "dictionary.txt";
    FILE *f;
    char c;
    if ((f = fopen(filename, "a+")) == NULL)
    {
        puts("File cannot be opened!");
        exit(1);
    }

    char word[255];
    char hata[255];

    printf("Word: ");
    scanf("%s", word);

    char buff[1024];

    while (fgets(buff, 1024, f))
    {

        buff[strcspn(buff, "\n")] = 0;

        char *token = strtok(buff, "|");
        char *wordFromFile, *hataFromFile;

        int i = 0;
        while (token != NULL)
        {
            if (i == 0)
            {
                hataFromFile = token;
            }
            else
            {
                wordFromFile = token;
            }

            token = strtok(NULL, "|");
            i++;
        }

        if (strcmp(word, wordFromFile) == 0)
        {
            printf("Means : %s\n", hataFromFile);
            break;
        }
    }
}
void english()
{

    char *filename = "dictionary.txt";
    FILE *f;
    char c;
    if ((f = fopen(filename, "a+")) == NULL)
    {
        puts("File cannot be opened!");
        exit(1);
    }

    char word[255];
    char hata[255];

    printf("Word : ");
    scanf("%s", hata);

    char buff[1024];
    char buff2[1024];

    while (fgets(buff2, 1024, f))
    {

        buff[strcspn(buff2, "\n")] = 0;

        char *token = strtok(buff2, "|");
        char *wordFromFile, *hataFromFile;

        int i = 0;
        while (token != NULL)
        {
            if (i == 0)
            {
                hataFromFile = token;
            }
            else
            {
                wordFromFile = token;
            }

            token = strtok(NULL, "|");
            i++;
        }

        if (strcmp(hata, hataFromFile) == 0)
        {
            printf("Means : %s\n", wordFromFile);
            break;
        }
    }
}
void input()
{
    char *filename = "dictionary.txt";
    FILE *f;
    char c;
    if ((f = fopen(filename, "a+")) == NULL)
    {
        puts("File cannot be opened!");
        exit(1);
    }

    char word[255];
    char hata[255];
    char buff[1024];

    printf("Add New Word : ");
    c = getchar();
    if ((f = fopen(filename, "a+")) == NULL)
    {
        puts("File cannot be opened!");
        exit(1);
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        putc(c, f);
    }

    putc('\n', f);
    fclose(f);
}