#include "server.h"

void fill_struct_array(struct data_string* list_of_lines, char* string, int number_lines)
{
    int length = 0;
    char* new_line_pos = 0;
    for (int i = 0; i < number_lines; i++)
    {
        new_line_pos = strchr(string, '\0');
        length = new_line_pos - string + 1;
        list_of_lines[i].str = (char*)calloc(length, sizeof(char));

        strncpy(list_of_lines[i].str, string, length - 1);

        list_of_lines[i].length = length - 1;
        string = string + length;
    }
}
