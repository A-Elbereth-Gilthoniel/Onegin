#include "server.h"

size_t find_file_size(FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    size_t n = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    assert(n > 2 && "File is empty");
    return n;
}
