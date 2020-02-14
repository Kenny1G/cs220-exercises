#include "string_functions.h"
#include <string.h>
/*
    Returns in the third argument the concatenation of the first
    argument and the second argument, provided that there is
    sufficient space in third argument, as specified by the fourth.
    e.g.
        concat("alpha", "beta", result, 10) puts "alphabeta" into result and returns 0
        concat("alpha", "gamma", result, 10) puts nothing into result and returns 1
*/
int concat(const char word1[], const char word2[], char result[], int result_capacity){

   //TODO: replace the following stub with a correct function body so that 
   //      this function behaves as indicated in the comment above
   //
   //NOTE: you may not use the strcat or strcpy library functions in your solution!
   int length1 = strlen(word1);
   int length2 = strlen(word2);
   int total_length = length1 + length2;

   if ((total_length) >= result_capacity)
   {
	   return 1;
   }
   else
   {
	   for(int i = 0; i < length1; ++i)
	   {
		   result[i] = word1[i];
	   }
	   for (int j = length1; j < total_length; ++j)
	   {
		   result[j] = word2[j-length1];
	   }
	   result[total_length] = '\0';
	   return 0;
   }
   return -1;

}
