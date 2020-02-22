// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#include "dnasearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: change this to return an int instead and pass an array
// into it where it'll copy the characters to.

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
    int i = 0;
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
                file_array[i] = cRet;
                ++i;
                break;
            default:
                printf("Invalid text \n");
                return 2;
        }
        iRet = fscanf(fileptr, " %c ", &cRet);
    }

    fclose(fileptr);
    return file_array;
}