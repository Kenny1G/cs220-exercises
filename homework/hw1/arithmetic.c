// name: Kenneth Oseleononmen
// ID:   KOSELEO1
#include <stdio.h>

#define YES 1
#define NO 0
int main(void)
{
	int willMultiplyNext = YES;
	int isNumberExpected = YES;
	float resultSoFar = 1.0f;
	float number = 0.0f;
	char operator = 'c';
	while (scanf(" %f %c ", &number, &operator) != EOF)
	{
		if (isNumberExpected)
		{
			if (willMultiplyNext)
				resultSoFar *= number;
			else
			{
				if (number != 0)
					resultSoFar /= number;
				else
				{
					printf("\ndivision by zero");
					return 2;
				}
			}
			isNumberExpected = NO;
		}
		else if (operator== '*' && isNumberExpected == NO)
		{
			willMultiplyNext = YES;
			isNumberExpected = YES;
		}
		else if (operator== '/' && isNumberExpected == NO)
		{
			willMultiplyNext = NO;
			isNumberExpected = YES;
		}
		else if ( (operator == '/' || operator == '*') && isNumberExpected == YES)
		{
			printf("\nmalformed expression");
			return 1;
		}
	}
	printf("\n%f", resultSoFar);
}