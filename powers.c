// James Hall
// Spring 2018
// Program calculates the result of a base raised to an exponent

#include "stdio.h"
#include "math.h"

int power(int b, int e)
{
  if (e != 0)
     return b * power(b, e-1);
  else
    return 1;
}

int main(void)
{
  int i;
  int base, res, expo = 0;

  for (i=0; i <999; i++)
  {
	  printf("Input a base and an exponent, 0 0 to exit: ");
	  scanf("%d %d", &base, &expo);

	  if(base == 0 && expo == 0)
	  {
		  printf("Good-Bye");
		  break;
	  }
	  res = power(base, expo);
	  printf("%d is returned\n\n", res);
  }

  return 0;
}
