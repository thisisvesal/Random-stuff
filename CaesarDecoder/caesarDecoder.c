#include <stdio.h>

#define SMALL 0
#define CAPITAL 1
#define NOTLETTER 2

char addToSmallChar(char first, int i)
{if (first + i <= 'z')
    {
        return first + i;
    }
    else
    {
        return first + i - 26;
    }
}

char addToCapitalChar(char first, int i)
{
    if (first + i <= 'Z')
    {
        return first + i;
    }
    else
    {
        return first + i - 26;
    }
}

int findLetterType(char letter)
{
    if ('a' <= letter && letter <= 'z')
    {
        return SMALL;
    }
    else if ('A' <= letter && letter <= 'Z')
    {
        return CAPITAL;
    }
    return NOTLETTER;
    
}

int main()
{
    char first[100] = "vla soxv ilyh";
    char result[100];
    printf("Welcome to \"Caesar Code Decoder\"\n");
    printf("Enter the encoded message: ");
    gets(first);
    printf("\n");
    
    for (int i = 1; i < 26; i++)
    {
        int j;
        for (j = 0; first[j]; j++)
        {
            if (findLetterType(first[j]) == SMALL)
            {
                result[j] = addToSmallChar(first[j], i);
            }
            else if (findLetterType(first[j]) == CAPITAL)
            {
                result[j] = addToCapitalChar(first[j], i);
            }
            else if (findLetterType(first[j] == NOTLETTER))
            {
                result[j] = first[j];
            }  
        }
        result[j] = 0;
        printf("%s\n", result);
        if (i % 5 == 0)
        {
            char response[10];
            printf("Did you find the answer in the list?(y/n) ");
            scanf("%s", response);
            if (response[0] == 'y')
            {
                printf("Good! Thanks for using this program :)\n");
                return 0;
            }
            printf("\n");
        }
    }

    printf("Your message is probably not a caesar code.\n");
    printf("You can look for other decoding methods online.\n");

    return 0;
}