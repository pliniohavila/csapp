#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char  *get_line()
{
  char buf[4];
  char *result;
  
  gets(buf);
  result = malloc(strlen(buf));
  strcpy(result, buf);

  return (result);
}

int   main(void)
{
  char *word;

  word = get_line();

  printf("word: %s\n", word);

  free(word);

  return (0);
}