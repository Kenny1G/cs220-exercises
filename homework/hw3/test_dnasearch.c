// name: Kenneth Oseleononmen
// ID:   KOSELEO1

#include "dnasearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


char* test_parse_file(const char* filename, const char* expected)
{

    char* actual = malloc(15001 * sizeof(char));
    if (actual == NULL)
    {
        printf("test_dnasearch::test_parse_file malloc for file_array failed \n");
    }
    parse_file(filename, actual);


    for (int i = 1; (unsigned) i < strlen(expected); ++i)
    {
        assert(actual[i] == expected[i-1]);
        
    }
    return actual;
}

int test_pattern_match(char *test_text, int lent, char* test_pattern, int lenp)
{

    int total_matches = 0;
    int iRet = pattern_match(test_text, lent, test_pattern, lenp, 0);
    while (iRet != -1)
    {
        printf(" %d ", iRet);
        ++total_matches;
        iRet = pattern_match(test_text, lent, test_pattern, lenp, iRet + 1);
    }
    return total_matches;
}
int main()
{
    char *array = test_parse_file("test.txt", "CATATTACGATTACA");

    char test1[] = {'t', 'a', 'c'};
    assert(test_pattern_match(++array, array[0], test1, sizeof(test1)/sizeof(char)) == 2);
}

