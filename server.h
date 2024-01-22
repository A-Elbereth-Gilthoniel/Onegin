#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>


struct data_string {
    char* str;
    int length;
};

enum SORT {
    STRAIGHT = 0,
    REVERSE  = 1
};


int find_number_lines(char* string);
char *str_replace(char *orig, char *rep, char *with);
char* string_filter(char* string, int size);
void bubble_sort(struct data_string* arr, int size, enum SORT order);
void reverse(char* string);
size_t find_file_size(FILE* fp);
void fill_struct_array(struct data_string* list_of_lines, char* string, int number_lines);
char* r_replace(char *orig, int size);
void quick_sort(int (*cmptor)(struct data_string, struct data_string), struct data_string* arr, int left, int right);
int reverse_cmptor(struct data_string str1, struct data_string str2);
int cmptor(struct data_string str1, struct data_string str2);


#endif  //SERVER_H
