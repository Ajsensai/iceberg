# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main (int argc, char *argv[]){
    int j;
    // print the array bfore sorting
    for (j = 0; j < ASIZEE, j++)
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