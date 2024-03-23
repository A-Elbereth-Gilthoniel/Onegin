#include "server.h"

//------------------------------------------------------------------------------------

char *str_replace(char *orig, char *change, char *with)
{
    char* result;
    char* insert_point;
    char* pos_of_change;
    char* medium;

    int change_number = 0;

    assert((orig && change) && "The necessary arguments of the 'str_replace' function are not set");
    int len_change = strlen(change);
    assert(len_change != 0 && "The string to be replaced is empty");
    if (!with)
        with = "";
    int len_with = strlen(with);

    insert_point = orig;
    for (change_number = 0; pos_of_change = strstr(insert_point, change); change_number++)
    {
        insert_point = pos_of_change + len_change;
    }

    medium = result = calloc(strlen(orig) - (len_change - len_with) * change_number + 1, sizeof(char));



    int len_between = 0;
    while (change_number--)
    {
        insert_point = strstr(orig, change);
        len_between = insert_point - orig;
        medium = strncpy(medium, orig, len_between) + len_between;
        medium = strcpy(medium, with) + len_with;
        orig = orig + len_between + len_change;
    }
    strcpy(medium, orig);
    return result;
}

//-------------------------------------------------------------------------------

char* r_replace(char *orig, int size)
{
    char* result;
    char* new_str = result = (char*) calloc(size + 1, sizeof(char));
    char* insert_point;
    int n = 0;

    while (insert_point = strstr(orig, "\r"))
    {
        n = insert_point - orig;
        new_str = strncpy(new_str, orig, n) + n;
        orig = orig + n + 1;
    }

    strcpy(new_str, orig);
    return result;
}

//------------------------------------------------------------------------

void reverse(char string[])
{
    int length = strlen(string);
    int temp, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

//-------------------------------------------------------------------------

char* string_filter(char* string, int size)
{
    char *filtered_str = (char*) calloc(size + 1, sizeof(char));
    int i = 0;
    int first_symbol = 1;
    int index_of_first_symbol = 0;
    int index_of_last_symbol = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            filtered_str[i] = string[i] + 32;
        }
        else
            filtered_str[i] = string[i];

        if (filtered_str[i] >= 'a' && filtered_str[i] <= 'z' && first_symbol == 1)
        {
            index_of_first_symbol = i;
            first_symbol = 0;
        }
        if (filtered_str[i] >= 'a' && filtered_str[i] <= 'z')
            index_of_last_symbol = i;
    }
    char *final_filtered_str = (char*) calloc(index_of_last_symbol - index_of_first_symbol + 2, sizeof(char));
    strncpy(final_filtered_str, filtered_str + index_of_first_symbol, index_of_last_symbol - index_of_first_symbol + 1);
    free(filtered_str);
    return final_filtered_str;
}

//------------------------------------------------------------------------------

int find_number_lines(char* string)
{
    int number_lines = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '\n')
            number_lines++;
    }
    if (string[strlen(string) - 1] != '\n')
        number_lines++;

    return number_lines;
}

//------------------------------------------------------------------------------

int cmptor(struct data_string str1, struct data_string str2)
{
    int ind1 = 0;
    int ind2 = 0;
    while((ind1 < str1.length) && (ind2 < str2.length))
    {
        char symbol1 = str1.str[ind1];
        char symbol2 = str2.str[ind2];

        if (symbol2 >= 'A' && symbol2 <= 'Z')
                symbol2 = symbol2 + 32;
        if (symbol1 >= 'A' && symbol1 <= 'Z')
                symbol1 = symbol1 + 32;

        if ((symbol1 > 'z' || symbol1 < 'a') || (symbol2 > 'z' || symbol2 < 'a'))
        {
            if (symbol1 > 'z' || symbol1 < 'a')
                ind1++;
            if (symbol2 > 'z' || symbol2 < 'a')
                ind2++;
        }
        else if (symbol1 > symbol2)
            return 1;
        else if (symbol1 < symbol2)
            return -1;
        else
        {
            ind1++;
            ind2++;
        }
    }
    if (str1.length == str2.length)
        return 0;
    if (str1.length > str2.length)
        return 1;
    return -1;
}

//---------------------------------------------------------------------

int reverse_cmptor(struct data_string str1, struct data_string str2)
{
    int ind1 = str1.length - 1;
    int ind2 = str2.length - 1;
    while((ind1 >= 0) && (ind2 >= 0))
    {
        char symbol1 = str1.str[ind1];
        char symbol2 = str2.str[ind2];

        if (symbol2 >= 'A' && symbol2 <= 'Z')
                symbol2 = symbol2 + 32;
        if (symbol1 >= 'A' && symbol1 <= 'Z')
                symbol1 = symbol1 + 32;

        if ((symbol1 > 'z' || symbol1 < 'a') || (symbol2 > 'z' || symbol2 < 'a'))
        {
            if (symbol1 > 'z' || symbol1 < 'a')
                ind1--;
            if (symbol2 > 'z' || symbol2 < 'a')
                ind2--;
        }
        else if (symbol1 > symbol2)
            return 1;
        else if (symbol1 < symbol2)
            return -1;
        else
        {
            ind1--;
            ind2--;
        }
    }
    if (str1.length == str2.length)
        return 0;
    if (str1.length > str2.length)
        return 1;
    return -1;
}
