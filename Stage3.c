/* Required imports*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void help(); /* help message*/

int comparisonFunction(const void *a, const void *b);

struct foo{
        double babies;
        int butter;
        int train;
        int history;
        short creator;
        short touch;
        char lumber;
        unsigned char disease;
        char cemetery[11];
        int year;
        int fall;
        unsigned short song;
        float toad;
        char coast;
        long birth;
        char boys;
        float crime;
};

int main (int argc, char *argv[]){
    FILE *input = fopen(argv[1], "rb");
    if (argc < 2){
        printf("Not enough or too many args provided.\n");
        help();
        return 1;
    }
    if (input == NULL){
        fprintf(stderr, "%s was either not found or invalid\n", argv[1]);
        help();
        return 1;
    }
    size_t size = 65;
    fseek(input, 0, SEEK_END);
    long filesize = ftell(input);
    fseek(input, 0, SEEK_SET);
    int newsize;
    newsize = filesize / size;
    struct foo *s = malloc(newsize * sizeof(struct foo));

    for(int i = 0; i<newsize;i++){
        fread(&s[i].babies, sizeof(s[i].babies), 1, input);
        fread(&s[i].butter, sizeof(s[i].butter), 1, input);
        fread(&s[i].train, sizeof(s[i].train), 1, input);
        fread(&s[i].history, sizeof(s[i].history), 1, input);
        fread(&s[i].creator, sizeof(s[i].creator), 1, input);
        fread(&s[i].touch, sizeof(s[i].touch), 1, input);
        fread(&s[i].lumber, sizeof(s[i].lumber), 1, input);
        fread(&s[i].disease, sizeof(s[i].disease), 1, input);
        fread(&s[i].cemetery, sizeof(s[i].cemetery), 1, input);
        fread(&s[i].year, sizeof(s[i].year), 1, input);
        fread(&s[i].fall, sizeof(s[i].fall), 1, input);
        fread(&s[i].song, sizeof(s[i].song), 1, input);
        fread(&s[i].toad, sizeof(s[i].toad), 1, input);
        fread(&s[i].coast, sizeof(s[i].coast), 1, input);
        fread(&s[i].birth, sizeof(s[i].birth), 1, input);
        fread(&s[i].boys, sizeof(s[i].boys), 1, input);
        fread(&s[i].crime, sizeof(s[i].crime), 1, input);
    }
    fclose(input);

 /* organising array*/
 /* if number of records is > 1 -> perform Qsort */
    if (newsize > 1){
        qsort(s,newsize, sizeof(struct foo), comparisonFunction);
    }

    FILE *fout = fopen(argv[2], "wb");
    if(fout == NULL){
        fprintf(stderr, "error");
        fout = fopen("somefile.txt", "wb");
    }

    for (int i = 0; i<newsize; i++){
        fwrite(&s[i].babies, sizeof(s[i].babies), 1, input);
        fwrite(&s[i].butter, sizeof(s[i].butter), 1, input);
        fwrite(&s[i].train, sizeof(s[i].train), 1, input);
        fwrite(&s[i].history, sizeof(s[i].history), 1, input);
        fwrite(&s[i].creator, sizeof(s[i].creator), 1, input);
        fwrite(&s[i].touch, sizeof(s[i].touch), 1, input);
        fwrite(&s[i].lumber, sizeof(s[i].lumber), 1, input);
        fwrite(&s[i].disease, sizeof(s[i].disease), 1, input);
        fwrite(&s[i].cemetery, sizeof(s[i].cemetery), 1, input);
        fwrite(&s[i].year, sizeof(s[i].year), 1, input);
        fwrite(&s[i].fall, sizeof(s[i].fall), 1, input);
        fwrite(&s[i].song, sizeof(s[i].song), 1, input);
        fwrite(&s[i].toad, sizeof(s[i].toad), 1, input);
        fwrite(&s[i].coast, sizeof(s[i].coast), 1, input);
        fwrite(&s[i].birth, sizeof(s[i].birth), 1, input);
        fwrite(&s[i].boys, sizeof(s[i].boys), 1, input);
        fwrite(&s[i].crime, sizeof(s[i].crime), 1, input);
    }
    fclose(fout);

    free(s);
    return 0;
}



void help(){
    printf("This program takes a binary file input and turns it into a usable struct. The struct is then outputted in the specified format\n");
}

/* new function to support comparison*/
int comparisonFunction(const void *a, const void *b){
    const struct foo *pointerA = (const struct foo *)a; /* Recasting A*/
    const struct foo *pointerB = (const struct foo *)b; /* Recasting B*/
    /* Start comparison */
    /* Qsort returns 1 if value > next. 0 if value = next. -1 if value < next */
    /* fall DEC */
    if (pointerA->fall < pointerB->fall){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->fall > pointerB->fall){
        return -1; /* if a is more than b, place a before b*/
    }
    /* butter ASC */
    if (pointerA->butter < pointerB->butter){
        return -1; /* If a is less than b, place a after b*/
    }
    if (pointerA->butter > pointerB->butter){
        return 1; /* if a is more than b, place a before b*/
    }
    /* train  ASC */
    if (pointerA->train < pointerB->train){
        return -1; /* If a is less than b, place a after b*/
    }
    if (pointerA->train > pointerB->train){
        return 1; /* if a is more than b, place a before b*/
    }
    /* history DEC */
    if (pointerA->history < pointerB->history){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->history > pointerB->history){
        return -1; /* if a is more than b, place a before b*/
    }
    /* birth ASC */
    if (pointerA->birth < pointerB->birth){
        return -1; /* If a is less than b, place a after b*/
    }
    if (pointerA->birth > pointerB->birth){
        return 1; /* if a is more than b, place a before b*/
    }
    /* creator DEC */
    if (pointerA->creator < pointerB->creator){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->creator > pointerB->creator){
        return -1; /* if a is more than b, place a before b*/
    }
    /* cemetary ASC STRING = USE COMPARE FUNCTION*/
    if (!strcmp(a->cemetery, b->cemetery) == 0)
    {
        return strcmp(a->cemetery, b->cemetery);
    }
    /* song DEC */
    if (pointerA->song < pointerB->song){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->song > pointerB->song){
        return -1; /* if a is more than b, place a before b*/
    }
    /* lumber DEC */
    if (pointerA->lumber < pointerB->lumber){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->lumber > pointerB->lumber){
        return -1; /* if a is more than b, place a before b*/
    }
    /* crime DEC */
    if (pointerA->crime < pointerB->crime){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->crime > pointerB->crime){
        return -1; /* if a is more than b, place a before b*/
    }
    /* boys ASC */
    if (pointerA->boys < pointerB->boys){
        return -1; /* If a is less than b, place a after b*/
    }
    if (pointerA->boys > pointerB->boys){
        return 1; /* if a is more than b, place a before b*/
    }
    /* touch DEC */
    if (pointerA->touch < pointerB->touch){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->touch > pointerB->touch){
        return -1; /* if a is more than b, place a before b*/
    }
    /* disease ASC */
    if (pointerA->disease < pointerB->disease){
        return -1; /* If a is less than b, place a after b*/
    }
    if (pointerA->disease > pointerB->disease){
        return 1; /* if a is more than b, place a before b*/
    }
    /* coast DEC */
    if (pointerA->coast < pointerB->coast){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->coast > pointerB->coast){
        return -1; /* if a is more than b, place a before b*/
    }
    /* year DEC */
    if (pointerA->year < pointerB->year){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->year > pointerB->year){
        return -1; /* if a is more than b, place a before b*/
    }
    /* babies DEC */
    if (pointerA->babies < pointerB->babies){
        return 1; /* If a is less than b, place a after b*/
    }
    if (pointerA->babies > pointerB->babies){
        return -1; /* if a is more than b, place a before b*/
    }
    /* toad ASC */
    if (pointerA->toad < pointerB->toad){
        return -1; /* If a is less than b, place a after b*/
    }
    if (pointerA->toad > pointerB->toad){
        return 1; /* if a is more than b, place a before b*/
    }
    /* final return*/
    return 0;
}