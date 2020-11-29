#include "string_tools.h"

int read_line(FILE *fp, char str[], int size)
{
    int ch, i = 0;
    while ((ch=fgetc(fp)) != '\n' && ch != EOF )
        if ( i < size-1 )
            str[i++] = ch;

    str[i] = '\0';
    return i;
}