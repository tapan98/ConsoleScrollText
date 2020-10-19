#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned int GetRows(char* text)
{
    char c = 0;
    int rows;

    if ( text != NULL && ((*text) != '\0') && ((*text) != EOF))
    {
        rows = 1;

        do
        {
            c = *(text++);
            if (c == '\n') rows++;
        } while (c != '\0');

    }
    else    rows = 0;

    return rows;
}

char* GetRowPointer(char* text, int row)
{
    int currentRow = 0;


    if ( text != NULL && (*text) != '\0' && (*text) != EOF)
    {

        while (currentRow < row)
        {
            while (*(text++) != '\n' && *text != 0);

            if ( *text == 0 ) return NULL;
            
            currentRow++;
        }

        return text;
    }

    return NULL;
}

unsigned int GetCharlengthOfRow(char* text)
{
    char c;
    unsigned int length = 0;

    if ( text != NULL && *text)
    {
        do
        {

            c = *(text++);
            length++;

        } while (c != '\n' && c != 0);
    }

    return length;
}

int StringToInt(char* string)
{
    int i, length;
    int number = 0;

    if (string != NULL)
    {

        length = strlen(string);

        for (i = 0; i < length; i++)
        {
            if (string[i] > 47 && string[i] < 58)
            {
                number = number * 10 + (string[i] - '0');
            }
            else return 0;
        }

    }
    return number;
}
