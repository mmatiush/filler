#include <stdlib.h>

int main(void)
{
    char *str;
    str = (char*)malloc(50);
    free(str);
    str = NULL;
    return (1);
}