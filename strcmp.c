//James Hall 8.29.18
//Program does a non-case sensitive strcmp

#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int strcmp_i(const char *str1, const char *str2)
{
  int res = 0;

  int c_size = sizeof(char);
  int str1_length = strlen(str1);
  int str2_length = strlen(str2);

  char *swap1 = NULL;
  char *swap2 = NULL;

  swap1 = malloc(sizeof(char) * (str1_length + 1));
  swap2 = malloc(sizeof(char) * (str2_length + 1));

//Converts Strings To Lowercase
  for(int i = 0; i < str1_length; i++)
  {
    *(swap1) = tolower(*str1);
    swap1 = swap1 + c_size;
  }
  swap1 = (swap1 - c_size * str1_length);

  for(int i = 0; i < str2_length; i++)
  {
    *(swap2) = tolower(*str2);
    swap2 = swap2 + c_size;
  }
  swap2 = (swap2 - c_size * str2_length);


  res = strcmp(swap1, swap2);

  free(swap1);
  free(swap2);

  return res;

}

int main(int argc, char **argv)
{
  int c_size = sizeof(char);

  char *string1 = NULL;
  char *string2 = NULL;

  if(argv[1] != NULL)
    string1 = argv[1];
  else
  {
    printf("Invalid Input, Good-Bye\n");
    return 0;
  }

  if(argv[2] != NULL)
    string2 = argv[2];
  else
  {
    printf("Invalid Input, Good-Bye\n");
    return 0;
  }

  printf("\nString 1: %s", string1);
  printf("\nString 2: %s", string2);

  printf("\nPassing Strings Into String Compare...\n");

  if(strcmp_i(string1, string2) != 0)
    printf("\nThese are not the same words");
  else
    printf("\nThese are the same words");

  printf("\nString 1: %s", string1);
  printf("\nString 2: %s\n", string2);

  return 0;

}
