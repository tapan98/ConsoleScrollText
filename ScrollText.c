#include "include/TextInfo.h"
#include "include/NewlineToArrays.h"
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>


void ScrollText(char** text, int rowsToPrint, int totalRows, int scrollJump)
{

    int startRow = 0;
    char userInput = -1;
    int shouldPrint = 1;
    int row = 0;

    if (text == NULL) return;

    do
    {

        if (shouldPrint)
        {

            system("cls");

            for (row = startRow; row < (rowsToPrint+startRow) && row < totalRows; row++)
            {
                puts(text[row]);
            }

            if (row == totalRows) printf("\n--END--");
        }

        userInput = getch();

        if (userInput == -32) // special key
        {
            switch (getch())
            {
            case 72: //UP arrow key

                if (startRow - (scrollJump - 1) > 0) // scroll up
                {
                    startRow -= scrollJump; shouldPrint = 1;
                }
                else if (startRow > 0)
                {
                    startRow = 0; shouldPrint = 1;
                }
                else
                {
                    shouldPrint = 0;
                }


                break;

            case 80: //Down arrow key

                if ( (totalRows - startRow + 1) - scrollJump > rowsToPrint) // don't want to strip rows
                {
                    startRow += scrollJump;
                    shouldPrint = 1;
                }
                else if ( ( totalRows - startRow ) > rowsToPrint)
                {
                    startRow = totalRows - rowsToPrint; 
                    shouldPrint = 1;
                }
                else
                {
                    shouldPrint = 0;
                }


                break;
            }
        }

    } while (userInput != 'q' && userInput != 'Q' && userInput != 27);

}