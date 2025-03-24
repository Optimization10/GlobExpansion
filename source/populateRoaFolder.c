#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>


void Transfer_File_To_Roa_Folder(char *fileName)
{
    char newname[3000];
    strcpy(newname, fileName);

    // Remove prefix
    char *slash = strrchr(newname, '/');
    if (slash != NULL) memmove(newname, slash + 1, strlen(slash) + 1) ;
    else
    {
        printf("\nNo slash\n") ;
        return ;
    }

    // Remove extension
    char *dot = strrchr(newname, '.');
    if (dot != NULL) *dot = '\0';
    else
    {
        printf("\nNo dot\n") ;
        return ;
    }

    // Prepare the final name with "roa/" prefix and ".roa" extension
    char final_name[3000];
    if (snprintf(final_name, sizeof(final_name), "roa/%s.roa", newname) >= sizeof(final_name))
    {
        printf("Filename too long to process.\n");
        return;
    }

    // Save this new file to ROA folder
    FILE *file = fopen(final_name, "w");
    if (file == NULL)
    {
        printf("Failed to open file");
        return;
    }
    fputc('a', file);
    fclose(file);
}



int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        Transfer_File_To_Roa_Folder(argv[i]) ;
    }
    return 0 ;
}