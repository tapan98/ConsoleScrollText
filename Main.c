#include <stdio.h>
#include <stdlib.h>
#include "include/ScrollText.h"
#include "include/NewlineToArrays.h"
#include "include/TextInfo.h"

void printHelp(char* name)
{
    printf("\nUsage:\n");
    printf("\n%s [-r <Number of rows to display>] [-j <Number of Scroll jumps>]\n", name);
}

int main(int argc, char** argv)
{

    char c;
    int size = 1, i;
    unsigned int index = 0;
    char* text = (char*)calloc(1, 1);
    char** buffer = NULL;
    int rowsToPrint = 25, scrollJumps = 2;

    if (text == NULL) return -1;

    // char largetext[] = "1. This is a sample text\n2. This is a sample text\n3. This is a sample text\n4. This is a sample text\n5. This is a sample text\n6. This is a sample text\n7. This is a sample text\n8. This is a sample text\n9. This is a sample text\n10. This is a sample text\n11. This is a sample text\n12. This is a sample text\n13. This is a sample text\n14. This is a sample text\n15. This is a sample text\n16. This is a sample text\n17. This is a sample text\n18. This is a sample text\n19. This is a sample text\n20. This is a sample text\n21. This is a sample text\n22. This is a sample text\n23. This is a sample text\n24. This is a sample text\n25. This is a sample text\n26. This is a sample text\n27. This is a sample text\n28. This is a sample text\n29. This is a sample text\n30. This is a sample text\n31. This is a sample text\n32. This is a sample text\n33. This is a sample text\n34. This is a sample text\n35. This is a sample text\n36. This is a sample text\n37. This is a sample text\n38. This is a sample text\n39. This is a sample text\n40. This is a sample text\n41. This is a sample text\n42. This is a sample text\n43. This is a sample text\n44. This is a sample text\n45. This is a sample text\n46. This is a sample text\n47. This is a sample text\n48. This is a sample text\n49. This is a sample text\n50. This is a sample text";

    // handling command-line options and arguments
    if (argc > 1)
    {

        for (i = 1; i < argc; i++)
        {
            if (argv[i][0] == '-' || argv[i][0] == '/')
            {
                if ( i < argc && (argv[i][1] == 'r' || argv[i][1] == 'R') && ++i < argc && StringToInt( argv[i] ) > 0 )
                {

                    rowsToPrint = StringToInt(argv[i]);

                }
                else if ( i < argc && (argv[i][1] == 'j' || argv[i][1] == 'J') && ++i < argc && StringToInt( argv[i] ) > 0 )
                {

                    scrollJumps = StringToInt(argv[i]);

                }
                else
                {
                    printHelp(argv[0]);
                    return 0;
                }

            }else
            {
                printHelp(argv[0]);
                return 0;
            }
            
        }

    }

    // getting the reads
    while ((c = getc(stdin)) != EOF && (c != '\0'))
    {
        if (c == 4 || c == 26) c = '\0'; // ctrl+D signal or ctrl+Z signal

        if (text != NULL)
        {
            text[index++] = c;

            text = (char*)realloc(text, ++size);
            if (text == NULL) return -1;
        }

        if (c == 0) break;
    }
    text[index] = '\0';

    buffer = NewlineToArrays(text);

    ScrollText(buffer, rowsToPrint, GetRows(text), scrollJumps);

    free2dCharArray(buffer, GetRows(text));

    free(text);

    return 0;
}