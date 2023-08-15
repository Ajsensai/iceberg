# include <stdio.h>

int usage(){
    printf("Syntax: ./program filename -u\n");
    printf("Arguments:\n -u Upper\n -l Lower\n");
}

void upperLower(char *option, char *text){
    while (*text != '\0'){
        if (*option == 'u'){
            *text = (*text >= 'a' && *text <= 'z') ? (*text - 'a' + 'A') : *text;
        }
        else if (*option == 'l'){
            *text = (*text >= 'A' && *text <= 'Z') ? (*text - 'A' + 'a') : *text;
        }
        text++;
    }
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
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *text = (char *)malloc(file_size + 1);
    if (text == NULL){
        printf("Memory allocation error. \n");
        fclose(file);
        return 1;
    }
    fread(text, 1, file_size, file);
    text[file_size] = '\0';
    fclose(file);
    upperLower(option, text);
    printf("%s\n", text);
    free(text);
    return 0;
}