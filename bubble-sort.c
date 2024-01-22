#include "server.h"
//
// cmp, void* arr, int size, int elemSize
void bubble_sort(struct data_string* arr, int size, enum SORT order)
{
    char** filtered_arr = (char**) calloc(size + 1, sizeof(char*));

    for (int i = 0; i < size; i++)
    {
        filtered_arr[i] = string_filter(arr[i].str, arr[i].length);
        if (order == REVERSE)
            reverse(filtered_arr[i]);
    }


    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int i = 0; i < size-pass-1; i++)
        {
            if (strcmp(filtered_arr[i], filtered_arr[i+1]) > 0) // *(arr + i * elemSize)
            {
                char* temp2 = filtered_arr[i];
                filtered_arr[i] = filtered_arr[i+1];
                filtered_arr[i+1] = temp2;
                struct data_string temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    free(filtered_arr);
}
