# include <stdio.h>

int main (int argc, char *argv[])
{
    int count;
    printf ("This was called with \"%s\".\n", argv[0]);
    if (argc > 1)
    {
        for (i=1; i<argc; i++){
            printf("argv[%d] = %s\n", i, argv[i]);
        }
    }
    else
    {
        printf("The command has no other arguments.\n")
    }
    return 0;
}