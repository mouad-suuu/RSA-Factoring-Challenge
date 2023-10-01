#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void factor_number(int number) {
    char command[50];
    snprintf(command, sizeof(command), "factor %d", number);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int number = atoi(line);
        if (number == 0) {
            printf("Could not factor %s", line);
        } else {
            printf("%d=", number);
            factor_number(number);
        }
    }

    fclose(file);
    return 0;
}

