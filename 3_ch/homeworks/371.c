#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// https://zetcode.com/clang/fgets/
int main(void)
{
    char str[4];
    size_t len;
    
    len = 4;

    // fgets(str, sizeof(str), stdin);
    fgets(str, 3, stdin);

    printf("> size: %ld - %s\n", sizeof(str), str);

    // free(str);
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
