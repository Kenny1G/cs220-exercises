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
   char *dna_array = calloc(15001, sizeof(char));
   if (dna_array == 0)
   {
      printf("hw3.c::main malloc for dna_array failed \n");
   }
   iRet = parse_file(argv[1], dna_array);
   if (iRet != 0)
   {
      if (iRet != 2)
      {
         printf("dnasearch.c::parse_file File was not parsed successfully \n");
      }
      return 1;
   }

   // get patterns from user and find the matches
   char pattern_char;
   int pattern_size = 0;
   int matched = 0;
   char *user_pattern = malloc(15001 * sizeof(char));
   while (scanf("%c", &pattern_char) != EOF)
   {
      matched = 0;
      switch (toupper(pattern_char))
      {
      case 'A':
      case 'C':
      case 'G':
      case 'T':
         user_pattern[pattern_size] = toupper(pattern_char);
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
            matched = 1;
            show_match(pattern_size, user_pattern, dna_array);
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

   if (matched == 0)
   {
      printf("\n");
      show_match(pattern_size, user_pattern, dna_array);
   }

   free(dna_array);
   free(user_pattern);
}