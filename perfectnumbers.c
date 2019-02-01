// James Hall
// Spring 2018
// Program to determine and print perfect numbers

#include "stdio.h"

int main(void) {

	int i, j, max, num, sum = 0;

	printf("Up to what number would you like me to search for perfect numbers?  ");
	scanf("%d", &max);
  	puts("");

	//Loop For Perfect Numbers 1 To Input
	for(i = 1; i < max; i++) {
    num = 1;

	 //Checks for perfect numbers.
    while(num <= (i/2)) {
      if(i % num == 0)
        sum = sum + num;

	     num++;
    }

    if(sum == i) {

		 //Relays perfect number and prepares for factors.
		 printf("\n%d is a perfect number, it's factors are as follows: ", i);

		 //Tests for factors of i.
       for(j = 1; j <= i; j++)
       {
       	if(i % j == 0)
				printf("%d ", j);
      }
      printf("\n");
    }
    sum = 0;
  }
}
