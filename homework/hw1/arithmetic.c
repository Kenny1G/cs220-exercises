// name: Kenneth Oseleononmen
// ID:   KOSELEO1
#include <stdio.h>

#define YES 1
#define NO 0
int main(void)
{
	int willMultiplyNext = YES;
	float resultSoFar = 1.0f;
	int numOfUserInput = 0;

	printf("Please enter an arithmetic expression using * and / only:\n");

	float number;
	char operator;
	int iRet;
	while (( iRet = scanf(" %f %c ", &number, &operator)) != EOF)
	{
		numOfUserInput = iRet;
		if (numOfUserInput == 0)
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
			if (numOfUserInput != 1)
			{
				printf("\nmalformed expression\n");
				return 1;
			}
		}
	}

	if ( numOfUserInput != 1)
	{
		printf("\nmalformed expression\n");
	}
	else
	{
		printf("\n%f\n", resultSoFar);
	}
}