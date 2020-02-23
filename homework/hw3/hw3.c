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
   int iRet;
   if (argc != 2)
   {
      printf("Insufficient arguements; Usage: ./hw3 filename \n");
      return 1;
   }
   char *dna_array = malloc(15001 * sizeof(char));
   if (dna_array == 0)
   {
      printf("hw3.c::main malloc for dna_array failed \n");
   }
   iRet = parse_file(argv[1], dna_array);
   if (iRet != 0)
   {
      printf("dnasearch.c::parse_file File was not parsed successfully \n");
      return 1;
   }

   // get patterns from user and find the matches
   char pattern;
   int pattern_size = 0;
   int num_matches;
   char *user_pattern = malloc(15001 * sizeof(char));
   while (scanf("%c", &pattern) != EOF)
   {
      switch (toupper(pattern))
      {
      case 'A':
      case 'C':
      case 'G':
      case 'T':
         user_pattern[pattern_size] = toupper(pattern);
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
            for (int i = 0; i < pattern_size; ++i)
            {
               printf("%c", user_pattern[i]);
            }
            int match_offset = pattern_match(dna_array, dna_array[0], user_pattern, pattern_size, 0);
            while (match_offset != -1)
            {
               printf(" %d ", match_offset);
               ++num_matches;
               match_offset = pattern_match(dna_array, dna_array[0], user_pattern, pattern_size, match_offset + 1);
            }
            if (num_matches <= 0)
            {
               printf(" Not found\n");
            }
            else
            {
               printf("\n");
            }
            pattern_size = 0;
         }
         break;
      default:
         printf("Invalid pattern \n");
         free(dna_array);
         free(user_pattern);
         return 2;
      }
   }

   free(dna_array);
   free(user_pattern);
}