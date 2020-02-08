// name: Kenneth Oseleononmen
// ID:   KOSELEO1
#include <stdio.h>

#define YES 1
#define NO 0
int main(void)
{
	int willMultiplyNext = YES;
	float resultSoFar = 1.0f;
	float number;
	char operator;
	int errorIdentifier = 0;

	printf("Please enter an arithmetic expression using * and / only:\n");

	while (( errorIdentifier = scanf(" %f %c ", &number, &operator)) != EOF)
	{
		if (errorIdentifier == 0)
		{
			printf(" \nmalformed expression\n");
			return 1;
		}

		if (willMultiplyNext)
		{
			resultSoFar *= number;
		}
		else
		{
			if (number != 0)
			{
				resultSoFar /= number;
			}
			else
			{
				printf("division by zero\n");
				return 2;
			}
		}

		if (operator== '*')
		{
			willMultiplyNext = YES;
		}
		else if (operator== '/')
		{
			willMultiplyNext = NO;
		}
	}

	printf("\n%f\n", resultSoFar);
}