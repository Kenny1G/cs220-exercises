#include <stdio.h>
#include <math.h>
#include <assert.h>

// stdio.h for input & output functions
// math.h for pow, exp  (compile with -lm option)
// assert.h for assert

// This is a helper function; main function is below
// This function calculates the final value after 1 year
float compound_interest(float p, float r, int n) {
  // p is principal
  // r is annual rate
  // n is number of compoundings annually

  // n=1 means annual
  // n=12 means monthly
  // n=0 indicates continuous compounding

  assert(n >= 0);
  float amount;

  // Hint: use the pow(...) and exp(...) functions, declared in
  // math.h, for calculations below

  if(n > 0) {
    // TODO: Compute and return compound interest
    amount = p * pow((1 + (r/n)),n);
  } else {
    // TODO: Compute and return continuously compounded interest
    amount = p * exp(r);
  }
  return amount;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Error: must include input file name\n");
    return 1;
  }
  char * filename = argv[1];  // (copy) pointer to the filename

  // TODO: Open filename for reading, handle errors
  FILE * input = fopen(filename, "r");
  if (input == NULL)
  {
	  printf("input file open failed");
	  return 1;
  }

  // TODO: Open output.txt file for writing, handle errors
  FILE * output = fopen("output.txt", "w");
  if (output == NULL)
  {
	  printf("output file opening failed");
	  return 1;
  }

  // TODO: return non-0 if error prevented us from completing

  int line = 1;
  float p = 0.0;
  float r = 0.0;
  int parse;  // save return value of parsing attempt below

  // TODO: parse p, r from file, proceed with loop if successful
  parse = fscanf(input, " %f %f ", &p, &r);
  while (parse == 2) {
    
    line++;

    // If we're testing whether the user gave us sensible input,
    // we use `if` and print relevant error messages as usual

    if(p < 0.0) {
      printf("Error: principal less than 0 on line %d: %f\n", line, p);
      return 1;
    }
    if(r <= 0.0) {
      printf("Error: rate is <= 0 on line %d: %f\n", line, r);
      return 1;
    }

    // assert(...) statements are "sanity checks"; if false,
    // implies something is wrong with our program

    float ci_annual = compound_interest(p, r, 1);
    // compounding should only increase principal
    assert(ci_annual >= p);

    float ci_monthly = compound_interest(p, r, 12);
    // monthly should increase more than annual
    assert(ci_monthly >= ci_annual);

    float ci_cont = compound_interest(p, r, 0);
    // continuous should increase more than monthly
    assert(ci_cont >= ci_monthly);

    // TODO: print the three answers to the output file
    //       using "%0.2f %0.2f %0.2f\n" as the fprintf
    //       format string.  Print ci_annual, ci_monthly
    //       then ci_cont.
    fprintf(output, "%0.2f %0.2f %0.2f\n", ci_annual, ci_monthly, ci_cont); 
    parse = fscnf(input, "%f %f ", &p, & r);
  }

  // TODO: return non-0 if error prevented us from completing

  // TODO: use ferror to check both input and output for errors
  if (ferror(input))
  {
	  printf("somethings wrong with input file");
	  return 2;
  }
  if (ferror(output))
  {
	  printf("somethings wrong with output file");
	  return 2;
  }

  // TODO: close both input and output using fclose
  fclose(input);
  fclose(output);

  return 0;
}
