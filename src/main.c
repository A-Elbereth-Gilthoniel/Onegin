#include "server.h"

// argc argv
int main(int argc, char *argv[])
{
    char file_name[100] = FILE_REPOSITORY;
    strcat(file_name, argv[1]);
    struct data_string* list_of_lines = NULL;

    FILE *fp = fopen(file_name, "rb");
    assert(fp && ("WTF?! Where's this file ''%s''!?", file_name));

    size_t n = find_file_size(fp);

    char *string = (char*)calloc(n + 1, sizeof(char));
    fread(string, sizeof(char), n, fp);

    int number_lines = find_number_lines(string);
    string = r_replace(string, n);
    list_of_lines = (struct data_string*) calloc(number_lines, sizeof(struct data_string));

    fill_struct_array(list_of_lines, string, number_lines);

    free(string);
    fclose(fp);

    quick_sort(cmptor, list_of_lines, 0, number_lines - 1);

    for (int i = 0; i < number_lines; i++)
    {
        printf("%s\n",  list_of_lines[i].str);
    }

    printf("\n");

    quick_sort(reverse_cmptor, list_of_lines, 0, number_lines - 1);

    for (int i = 0; i < number_lines; i++)
        printf("%s\n",  list_of_lines[i].str);

    for (int i = 0; i < number_lines; i++)
        free(list_of_lines);
    return 1;
}
