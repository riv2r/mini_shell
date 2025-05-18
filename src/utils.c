#include "utils.h"
#include <string.h>

int CmpStr(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}