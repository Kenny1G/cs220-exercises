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
	int userHadInput = NO;

	printf("Please enter an arithmetic expression using * and / only:\n");

	while (( errorIdentifier = scanf(" %f %c ", &number, &operator)) != EOF)
	{
		if (errorIdentifier == 0)
		{
			printf(" \nmalformed expression\n");
			return 1;
		}
		else
		{
			userHadInput = YES;
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
				printf("\ndivision by zero\n");
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
		else
		{
			if (errorIdentifier != 1)
			{
				printf("\nmalformed expression\n");
				return 1;
			}
		}
	}

	if (!userHadInput)
	{
		printf("malformed expression\n");
	}
	else
	{
		printf("\n%f\n", resultSoFar);
	}
}