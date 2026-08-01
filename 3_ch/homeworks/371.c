#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// #define N 4

// https://zetcode.com/clang/fgets/

#include <unistd.h>

int     good_echo(void)
{
    char    *buf;
    char    *temp;
    size_t  size;
    
    size = 10;
    buf = malloc(sizeof(char) * size);
    
    if (buf != NULL) buf[0] = '\0';
    else return 1;

    while (fgets(buf + strlen(buf), size - strlen(buf), stdin) && buf[strlen(buf) - 1] != '\n') {

        if (strlen(buf) + 1 == size) {
            temp = realloc(buf, size * 2);
            if (!temp) {
                free(buf);
                return (1);
            }
            buf = temp;
            size *= 2;
        }
        
    }

    if (ferror(stdin) || feof(stdin)) {
        free(buf);
        return (1);
    }
    
    
    printf("%s", buf);

    free(buf);

    return (0);
}

int main(void)
{
    good_echo();
}

// int main(void)
// {
//     char temp[4];
//     char *str;
//     char *new;
//     size_t len;
//     size_t n;
    
//     str = NULL;
//     len = 0;

//     while (fgets(temp, sizeof(temp), stdin))
//     {
//         n = strlen(temp);

//         *new = realloc(str, len + n + 1);
//         if (!new) {
//             free(str);
//             return 1;
//         }

//         str = new;

//         memcpy(str + len, temp, n + 1);
//         len += n;

//         if (temp[n - 1] == '\n') break;
//     }

//     printf("%s", str);

//     free(str);
// }
