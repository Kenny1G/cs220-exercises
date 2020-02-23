// Kenny Oseleononmen
// koseleo1

#include "dnasearch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // parse user's text file
    int iRet; //iRet's are integers returned form functions that we use once and then don't need anymore
    if (argc != 2)
    {
        printf("hw3::main error. Usage: ./hw3 filename \n");
        return 1;
    }
    char *dna_array = malloc(15001 * sizeof(char));
    if (dna_array == 0)
    {
        printf("hw3::main malloc for dna_array failed \n");
    }
    iRet = parse_file(argv[1], dna_array);
    if (iRet != 0)
    {
        printf("hw3::main parse_file error \n");
        return 1;
    }

    // get patterns from user and match
    char nucleotide;
    int pattern_size = 0;
    int index = 1; // index starts at 1 because 0 holds size of user_pattern
    int num_matches;
    char *user_pattern = malloc(15001 * sizeof(char));
    while (scanf("%c", &nucleotide) != EOF)
    {
        switch (toupper(nucleotide))
        {
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            user_pattern[index] = toupper(nucleotide);
            ++index;
            ++pattern_size;
            break;
        case ' ':
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
            if (pattern_size > 0)
            {
                num_matches = 0;
                user_pattern[0] = pattern_size;
                for (int i = 0; i < pattern_size; ++i)
                {
                    printf("%c", user_pattern[i + 1]);
                }
                int match_offset = pattern_match(dna_array, dna_array[0], user_pattern, user_pattern[0], 0);
                while (match_offset != -1)
                {
                    printf(" %d ", match_offset);
                    ++num_matches;
                    match_offset =  pattern_match(dna_array, dna_array[0], user_pattern, user_pattern[0], match_offset + 1);
                }
                if (num_matches <= 0)
                {
                    printf(" Not found\n");
                }
                else
                {
                    printf("\n");
                }
                index = 0;
                pattern_size = 0;
            }
            break;
        default:
            printf("Invalid pattern \n");
        }
    }
}