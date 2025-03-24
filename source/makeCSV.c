#include <stdio.h>
#include <string.h>

// First argument (after the program name) is the name of the csv which should
// be used
int main(int argc, char **argv)
{
    FILE *csv = fopen(argv[1], "w");
    if (csv == NULL) {
        printf("Failed to open csv file");
        return 1;
    }

    // Remove the prefix and extension of each file name, and write in to csv
    for (int i = 2; i < argc; i++)
    {
        char *filename = argv[i];
        char newname[3000];
        strcpy(newname, filename);

        // Remove prefix
        char *slash = strrchr(newname, '/');
        if (slash != NULL) memmove(newname, slash + 1, strlen(slash));
        else
        {
            printf("\nNo slash");
            return 1;
        }

        // Remove extension
        char *dot = strrchr(newname, '.');
        if (dot != NULL) *dot = '\0';
        else
        {
            printf("\nNo dot");
            return 1;
        }

        fprintf(csv, "%s\n", newname);
    }
    fclose(csv) ;
    return 0 ;
}