#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  // Using malloc
  int *ptr_malloc = (int *) malloc (sizeof (int));
  *ptr_malloc = 10;
  printf ("Malloc: %d\n", *ptr_malloc);
  free (ptr_malloc);

  // Using calloc
  int *ptr_calloc = (int *) calloc (1, sizeof (int));
  *ptr_calloc = 20;
  printf ("Calloc: %d\n", *ptr_calloc);
  free (ptr_calloc);

  // Using realloc
  int *ptr_realloc = (int *) malloc (sizeof (int));
  *ptr_realloc = 30;
  printf ("Realloc (Before): %d\n", *ptr_realloc);
  ptr_realloc = (int *) realloc (ptr_realloc, 2 * sizeof (int));
  *(ptr_realloc + 1) = 40;
  printf ("Realloc (After): %d %d\n", *ptr_realloc, *(ptr_realloc + 1));
  free (ptr_realloc);

  return 0;
}
