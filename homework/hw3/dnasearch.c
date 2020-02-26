// name: Kenneth Oseleononmen
// ID:   KOSELEO1

#include "dnasearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int parse_file(const char *filename, char *file_array)
{
    FILE *fileptr = fopen(filename, "r");
    if (fileptr == NULL)
    {
        printf("dnasearch::parse_file error could not open file, %s \n", filename);
        return 1;
    }

    char cRet;
    int iRet = fscanf(fileptr, " %c ", &cRet);
    int i = 0;
    while (iRet != EOF)
    {
        switch (toupper(cRet))
        {
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            if (i <= 15000)
            {
                file_array[i] = cRet;
                ++i;
            }
            else
            {
                printf("Invalid text \n");
                return 2;
            }
            break;
        default:
            printf("Invalid text \n");
            return 2;
        }
        iRet = fscanf(fileptr, " %c ", &cRet);
    }
    if (i == 0)
    {
        printf("Invalid text \n");
        return 2;
    }
    fclose(fileptr);
    return 0;
}

int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at)
{
    int match;
    for (int i = start_at; i < tlen; ++i)
    {
        match = 1;

        for (int j = 0; j < plen; ++j)
        {
            if (toupper(p[j]) != toupper(t[i + j]))
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

void show_match(int pattern_size, char *user_pattern, char* dna_array)
{
    int num_matches = 0;
    for (int i = 0; i < pattern_size; ++i)
    {
        printf("%c", user_pattern[i]);
    }
    int match_offset = pattern_match(dna_array, strlen(dna_array), user_pattern, pattern_size, 0);
    while (match_offset != -1)
    {
        printf(" %d ", match_offset);
        ++num_matches;
        match_offset = pattern_match(dna_array, strlen(dna_array), user_pattern, pattern_size, match_offset + 1);
    }
    if (num_matches <= 0)
    {
        printf(" Not found\n");
    }
    else
    {
        printf("\n");
    }
}