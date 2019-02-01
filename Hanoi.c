// James Hall
// Spring 2018
// Hanoi Solver

#include "stdio.h"

// Recursively shifts the disks from peg to peg until they are stacked in order.
void towersHanoi (char from_peg, char aux_peg, char to_peg, int n) {

  if(n==1)
  {
    printf("\n%c to %c", from_peg,to_peg);
    return;
  }

  else
  {
    towersHanoi(from_peg, to_peg, aux_peg, n-1);
    towersHanoi(from_peg, aux_peg, to_peg, 1);
    towersHanoi(aux_peg, from_peg, to_peg, n-1);
  }
}


int main(void) {

  int numdisks;

  printf("Enter number of disks: ");
  scanf("%d", &numdisks);

  towersHanoi('1', '2', '3', numdisks);

  return 0;
}
