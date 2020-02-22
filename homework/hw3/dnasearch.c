// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#include "dnasearch.h"
#include <stdio.h>
#include <stdlib.h>

char* parse_file(const char* filename)
{
    char* file_array = malloc(15000 * sizeof(char));
    if (file_array == NULL)
    {
        printf("dnasearch::parse_file malloc for file_array failed \n");
    }

    FILE* fileptr = fopen(filename, "r");
    if (fileptr == NULL)
    {
        printf("dnasearch::parse_file error could not open file, %s", filename);
    }

    char cRet;
    int iRet = fscanf(fileptr, " %c ", &cRet);
    while (iRet != EOF)
    {
        switch(cRet)
        {
            case 'A':
            case 'a':
            case 'C':
            case 'c':
            case 'G':
            case 'g':
            case 'T':
            case 't':
            memcpy(file_array++, &cRet, sizeof(char));
            default:
                printf("Invalid text \n");
                return 2;
        }
        iRet = fscanf(fileptr, " %c ", ++file_array);
    }

    return file_array;
}