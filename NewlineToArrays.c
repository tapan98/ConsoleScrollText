#include <stdlib.h>
#include <stdio.h>
#include "include/TextInfo.h"

void free2dCharArray(char** toDealloc, const unsigned int rows)
{
    
    unsigned int i;

    for (i = 0; i < rows; i++)
    {

        free(toDealloc[i]);

    }

    free(toDealloc);

}

char** NewlineToArrays(char* text)
{

    char c = -1;
    unsigned long int row = 0, column = 0, columnLength = 2;
    unsigned int rowLength = GetRows(text);
    char* charPos = text;

    // 2d char array for null terminated string
    char** textArray = (char**)calloc(sizeof(char*), rowLength);
    if (textArray == NULL) return NULL;


    for (row = 0; row < rowLength; row++)
    {
        textArray[row] = (char*)calloc(sizeof(char), GetCharlengthOfRow( GetRowPointer( text, row ) ) + 1 );
        if (textArray[row] == NULL) return NULL;

        charPos = GetRowPointer(text, row);

        column = 0; // column reset for every row;

        do
        {

            if (textArray[row] != NULL)
            {
                if (charPos != NULL)
                {
                    c = *(charPos++);
                }
                else
                {
                    c = '\0';
                }

                if ( c != '\n' && c != '\0' )
                {
                    *(textArray[row] + column++) = c;
                }
                else if (c == '\0')
                {
                    *(textArray[row] + column) = '\0';
                }
                else
                {
                    *(textArray[row] + column) = '\0';
                }

            }else return NULL;

        } while ( c != '\0' && c != '\n' );
    }


    return textArray;

}