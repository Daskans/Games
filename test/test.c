#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    char *fname = "hello";
    FILE *file = fopen(fname, "w");
    fprintf(file,"hello world\n");
    fclose(file);
    file = fopen(fname, "w");
    fprintf(file,"goodbye world\n");
    fclose(file);
    return EXIT_SUCCESS;
}