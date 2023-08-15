# include <stdio.h>

int usage(){
    printf("Syntax: ./program filename -u\n");
    printf("Arguments:\n -u Upper\n -l Lower\n");
}

int main (int argc, char *argv[]){
    FILE *fp;
    char *filename;
    char *case;
    char ch;
    if (argc < 3){
        if (argc < 2){
            printf("Missing Filename\n");
            usage();
            return (1);
        }
        else{
            printf("Missing -u or -l\n");\
            usage();
            return (1);
        }
    }
    else{
        filename = argv[1];
        case = argv[2];
        printf("Filename: %s\n", filename);
        printf("Upper/Lower: %s\n", case);

    }
    fp = fopen(filename,"r");
    if (fp){
        printf("File contents:\n");
        while ( (ch = fgetc(fp)) != EOF){
            printf("%c", ch);
        }
    }
    else{
        printf("Failed to open the file\n");
    }
    return(0);
}