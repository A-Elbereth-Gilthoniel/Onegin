#include "server.h"


void quick_sort(int (*cmptor)(struct data_string, struct data_string), struct data_string* arr, int left, int right)
{
    struct data_string key_elem = arr[left];
    int l_border = left;
    int r_border = right;

    while (l_border < r_border)
    {
        while ((cmptor(arr[r_border], key_elem) >= 0) &&(l_border != r_border))
            r_border--;

        while ((cmptor(arr[l_border], key_elem) <= 0) && (l_border != r_border))
            l_border++;

        if (l_border != r_border)
        {
            struct data_string temp = arr[l_border];
            arr[l_border] = arr[r_border];
            arr[r_border] = temp;
        }

    }
    arr[left] = arr[r_border];
    arr[r_border] = key_elem;

    if (left < (r_border - 1))
        quick_sort(cmptor, arr, left, r_border - 1);
    if (right > (r_border + 1))
        quick_sort(cmptor, arr, r_border + 1, right);
}
