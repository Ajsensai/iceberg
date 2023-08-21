# include <stdio.h>
# include <stdlib.h>
# include <string.h>

static int cmpints(const void *p1, const void *p2)
{
    /* The actual arguments to this function are "pointers to
    int", but we need to access the integers, so first we
    cast the pointers to the actual type and then we
    dereference them to obtain the integer values */
    int *intp1 = (int *) p1;
    int *intp2 = (int *) p2;
    /* Compare and return comparison result
    * The result is >0 if the first int is greater than the
    * second.
    * The result is <0 if the first int is less than the
    * second.
    * The result is 0 if the two integers are equal.
    * We don't subtract the second int from the first because
    * there can be overflow that produces an incorrect return
    * value. */
    if (*intp1 > *intp2) return 1;
    if (*intp1 < *intp2) return -1;
    return 0;
}

# define ASIZE 10
static int a[ASIZE] = { 1, 3, 8, 7, 2, 4, 6, 5, 9, 0 };
// printf("Please enter a line:\n")
// ASIZE = getline(&line, &len, stdin);
// printf("You entered %s, which has %zu chars.\n", line, ASIZE -1);
// Modify the program, so that it reads an arbitrary number of integers from stdin until the user
// enters either EOF (Ctrl-D) or invalid input. These numbers should be stored in an array with
// dynamically allocated memory instead of a static array.



int main (int argc, char *argv[]){
    int j;
    // print the array bfore sorting
    // -------------
    char a[100];
   fprintf(stdin, "Enter a string :");
   fscanf(stdin,"%d", a);
   fprintf(stdout,"\nYou entered the following string: %s ", a);
   fprintf(stdout,"\n");
    // -------------
    for (j = 0; j < ASIZE; j++)
        printf("%d ", a[j]);
        printf("\n");
    // Sort the arror
    qsort(a, ASIZE, sizeof(int), cmpints);
    // Print the array after sorting
    for(j = 0; j < ASIZE; j++)
        printf("%d ", a[j]);
        printf("\n");
    return 0;
}