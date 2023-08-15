# include <stdio.h>

int usage(){
    printf("Syntax: ./program filename -u\n");
    printf("Arguments:\n -u Upper\n -l Lower\n");
}

int main (int argc, char *argv[]){
    if (argc != 3){
        usage();
        return 1;
    }
    char *option = argv[2];
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("File not found: %s\n", filename);
        return 1;
    }
    printf("And?....");
    return 0;
}