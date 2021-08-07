#include <unistd.h>
#include <stdlib.h>

// Uses write system call to display string to the standart output
int my_puts(const char *s)
{   
    // Count input string length
    unsigned int str_size = 0;
    for (const char *ch_p = s; *ch_p != '\0'; ++ch_p)
    {
        ++str_size;
    }

    // Allocate new string
    char *output_str = malloc(str_size + 2);

    unsigned int index = 0;
    
    // Copy input string to newly allocated
    for (; index < str_size; ++index)
    {
        output_str[index] = s[index];
    }

    // Add return char end null char
    output_str[index++] = '\n';
    output_str[index] = '\0';
    
    // System call
    write(1, output_str, str_size + 1);
    
    // Free allocated string
    free(output_str);

    return 1;
}

