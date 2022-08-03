#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    // text file name
    const char* fileName = "testFile.txt";

    // generate recommended memory size for file reading
    struct stat sb;
    stat(fileName, &sb);
    char *fileContent = malloc(sb.st_size);

    // open file
    FILE *filePointer;
    if ((filePointer = fopen(fileName, "r")) == NULL) {
        printf("Could not open file");
        // exit program
        exit(1);
    }

    // read text
    while (fscanf(filePointer, "%[^\n] ", fileContent) != EOF){
        printf("%s\n", fileContent);
    }

    fclose(filePointer);
    exit(EXIT_SUCCESS);
}
