// name: Kenneth Oseleononmen
// ID:   KOSELEO1

#include "dnasearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_parse_file(const char* filename)
{
    char *actual = parse_file(filename);
    
    char expected[] = {'C','A','T','A','T','T','A','C','G','A','T','T','A','C','A'};


    for (int i = 0; i < 15; i++)
    {
        assert(actual[i] == expected[i]);
    }
    free(actual);
}
int main()
{
    test_parse_file("test.txt");
}

