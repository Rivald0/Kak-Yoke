#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void english();
void batak();
void input();

int main()
{
    do
    {
        printf("\n++++++++++++++ Options +++++++++++++++\n");
        printf("+ 1. Bahasa Inggris -> Bahasa Batak  +\n");
        printf("+ 2. Bahasa Batak -> Bahasa Inggris  +\n");
        printf("+ 3. Add New Word                    +\n");
        printf("++++++++++++++++++++++++++++++++++++++\n");
        printf("Enter your option : ");

        int opt;
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            english();
            break;

        case 2:
            batak();
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

void english()
{

    char *filename = "dictionary.txt";
    FILE *f = fopen(filename, "a+");

    char word[255];
    char hata[255];
    char word2[255];

    printf("Word in English: ");
    scanf("%s", word);

    while (fscanf(f, "%s %s", hata, word2) != EOF)
    {
        if (strcmp(word, word2) == 0 && strcmp(word, hata))
        {
            printf("Hata in Batak: %s\n", hata);
            break;
        }
    }
    printf("\n");
    fclose(f);
}
void batak()
{
    char *filename = "dictionary.txt";
    FILE *f = fopen(filename, "a+");

    char word[255];
    char hata[255];
    char hata2[255];

    printf("Hata in Batak ");
    scanf("%s", hata);

    while (fscanf(f, "%s %s", hata2, word) != EOF)
    {
        if (strcmp(hata, hata2) == 0)
        {
            printf("Word in English: %s\n", word);
            break;
        }
    }
    printf("\n");
    fclose(f);
}

void input()
{
    char *filename = "dictionary.txt";
    FILE *f = fopen(filename, "a+");
    char c;

    char word[255];
    char hata[255];

    printf("Add New Word in Batak: ");
    scanf("%s", hata);

    printf("Add New Word : ");
    scanf("%s", word);

    fprintf(f, "%s %s\n", hata, word);
    printf("\n");
    fclose(f);
}