#include <stdio.h>

int main() {
    FILE *file;
    char line[230];
    int line_number = 1;

    file = fopen("file.txt", "r");

    if (file == NULL) {
        perror("Error opening file"); 
        return 1;
    }
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", line_number, line);
        line_number++;
    }

    if (ferror(file)) {
        perror("Error reading the file");
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}


