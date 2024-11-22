#include <stdio.h>
#include <ctype.h>
int main() {
    FILE *source, *destination;
    char ch;
    source = fopen("hello.txt", "r");
    if (source == NULL) {
        printf("Error commencing the hello file.\n");
        return 1;
    }

    destination = fopen("world.txt", "w");
    if (destination == NULL) {
        printf("Error commencing the  world file.\n");
        fclose(source);
        return 1;
    }

  
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);  
    }

    fclose(source);
    fclose(destination);

    printf("File being copied and converted to  the uppercase successfully.\n");
    return 0;
}

