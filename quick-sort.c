#include "server.h"


void quick_sort(char** filtered_arr, struct data_string* arr, int left, int right)
{
    char* key_elem = filtered_arr[left];    // Разрешающий элемент
    struct data_string orig_key_elem = arr[left];
    int l_border = left;
    int r_border = right;

    while (l_border < r_border)
    {
        while ((strcmp(filtered_arr[r_border], key_elem) >= 0) &&(l_border != r_border))
            r_border--;

        while ((strcmp(filtered_arr[l_border], key_elem) <= 0) && (l_border != r_border))
            l_border++;

        if (l_border != r_border)
        {
            char* temp2 = filtered_arr[l_border];
            filtered_arr[l_border] = filtered_arr[r_border];
            filtered_arr[r_border] = temp2;
            struct data_string temp = arr[l_border];
            arr[l_border] = arr[r_border];
            arr[r_border] = temp;
        }

    }
    filtered_arr[left] = filtered_arr[r_border];
    filtered_arr[r_border] = key_elem;
    arr[left] = arr[r_border];
    arr[r_border] = orig_key_elem;

    if (left < (r_border - 1))
        quick_sort(filtered_arr, arr, left, r_border - 1);
    if (right > (r_border + 1))
        quick_sort(filtered_arr, arr, r_border + 1, right);
}
