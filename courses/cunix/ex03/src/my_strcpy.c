// Copies content of src string to dest string
char *my_strcpy(char *dest, const char *src)
{   
    // Preserve start of string for future return
    char *ret = dest;

    // Iterate the string and copy char by char
    while (*src)
    {
        *dest = *src;
        ++src;
        ++dest;
    }

    // Add null char at the end of string
    *dest = '\0';

    return ret;
}

