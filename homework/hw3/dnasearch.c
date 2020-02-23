// name: Kenneth Oseleononmen
// ID:   KOSELEO1


#include "dnasearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//TODO: change this to return an int instead and pass an array
// into it where it'll copy the characters to.

int parse_file(const char* filename, char * file_array)
{
    FILE* fileptr = fopen(filename, "r");
    if (fileptr == NULL)
    {
        printf("dnasearch::parse_file error could not open file, %s \n", filename);
    }

    char cRet;
    int iRet = fscanf(fileptr, " %c ", &cRet);
    int i = 1;
    while (iRet != EOF)
    { 
        switch(toupper(cRet))
        {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
            // TODO: figure out why memcpy didn't work.
                file_array[i] = cRet;
                ++i;
                break;
            default:
                printf("Invalid text \n");
                return 2;
        }
        iRet = fscanf(fileptr, " %c ", &cRet);
    }

    file_array[0] = i;
    fclose(fileptr);
    return 0;
}


int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at)
{
    ++t;
    int match;
    for (int i = start_at; i < tlen; ++i)
    {
        match = 1;

        for (int j = 0; j < plen; ++j)
        {
            if (p[j] != t[i+j])
            {
                match = 0;
                break;
            }
        }
        if (match == 1)
        {
            return i;
        }
    }
    return -1;

}