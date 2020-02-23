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

void test_pattern_match(char *test_text, int lent, char* test_pattern, int lenp, int expected[], int expectedl)
{
    int actual[expectedl];

    int actual_index = 0;
    int iRet = pattern_match(test_text, lent, test_pattern, lenp, 0);
    while (iRet != -1)
    {
        printf(" %d ", iRet);
        actual[actual_index] = iRet;
        ++actual_index;
        iRet = pattern_match(test_text, lent, test_pattern, lenp, iRet + 1);
    }

    for (int i = 0; i < expectedl; ++i)
    {
        assert(actual[i] == expected[i]);
    }
}
int main()
{
    char *array = test_parse_file("test.txt", "CATATTACGATTACA");

    char test1[] = {'t', 'a', 'c'};
    int expected[] = {5, 11};
    test_pattern_match(array, (int) array[0], test1, sizeof(test1)/sizeof(char), expected, 2);

    char test2[] = {'a'};
    int expected2[] = {1, 3, 6, 9, 12, 14};
    test_pattern_match(array, (int) array[0], test2, sizeof(test2)/sizeof(char), expected2, 6);

    char test3[] = {'T','T','a'};
    int expected3[] = {4, 10};
    test_pattern_match(array, (int) array[0], test3, sizeof(test3)/sizeof(char), expected3, 2);

    char test4[] = {'g','C'};
    int expected4[0] = {};
    test_pattern_match(array, (int) array[0], test4, sizeof(test4)/sizeof(char), expected4, 0);

    free(array);



}

