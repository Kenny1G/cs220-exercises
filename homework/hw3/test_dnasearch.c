// name: Kenneth Oseleononmen
// ID:   KOSELEO1

#include "dnasearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/*
    @param filename name of the file you want to parse
    @param expected a c-string of the array you expect to get.
*/
char *test_parse_file(const char *filename, const char *expected)
{

    char *actual = calloc(15001, sizeof(char));
    if (actual == NULL)
    {
        printf("test_dnasearch::test_parse_file malloc for file_array failed \n");
    }
    int iRet = parse_file(filename, actual);
    assert(iRet == 0);

    for (int i = 0; (unsigned)i < strlen(expected); ++i)
    {
        assert(actual[i] == expected[i]);
    }
    return actual;
}
/*
    @param test_text the array from the text file
    @param test_pattern the pattern you would like to find
    @param expected your expected result an array of the offsets
    @param expectedl how many length of output you'd like to test
*/
void test_pattern_match(char *test_text, char *test_pattern, int expected[], int expectedl)
{
    int actual[15000];
    int lenp = strlen(test_pattern);

    int actual_index = 0;
    int iRet = pattern_match(test_text, strlen(test_text), test_pattern, lenp, 0);
    while (iRet != -1)
    {
        //printf(" %d ", iRet); //sanity check
        actual[actual_index] = iRet;
        ++actual_index;
        iRet = pattern_match(test_text, strlen(test_text), test_pattern, lenp, iRet + 1);
    }
    //printf("\n"); // sanity check
    if (expectedl == 0)
    {
        assert(actual_index == 0);
    }
    else
    {
        for (int i = 0; i < expectedl; ++i)
        {
            assert(actual[i] == expected[i]);
        }
    }
}
int main()
{
    FILE* fileptr = fopen("this_is_a_file_name_you_couldnt_possibly_have_on_your_computer.txt", "w");
    if (fileptr == 0)
    {
        printf("test_dnasearch.c:main() failed to create file test.txt");
    }
    fprintf(fileptr, "CA TATTAC\nGATT ACA");
    fclose(fileptr);
    char *array = test_parse_file("this_is_a_file_name_you_couldnt_possibly_have_on_your_computer.txt", "CATATTACGATTACA");

    char test1[] = "tac";
    int expected[] = {5, 11};
    test_pattern_match(array, test1, expected, 2);

    char test2[] = "a";
    int expected2[] = {1, 3, 6, 9, 12, 14};
    test_pattern_match(array, test2, expected2, 6);

    char test4[] = "gc";
    test_pattern_match(array, test4, 0, 0);

    char test5[] = "catattac";
    int expected5[] = {0};
    test_pattern_match(array, test5, expected5, 1);

    char test7[] = "goat";
    test_pattern_match(array, test7, 0, 0);

    printf("This is a message indicating successs \n");

    free(array);
}
