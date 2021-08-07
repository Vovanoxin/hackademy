// Takes two strings and returns their difference
int my_strcmp(const char *str1, const char *str2)
{   
    // Iterate string till chars becomes different or end reached
    while (*str1 && *str2 && *str1 == *str2)
    {
        ++str1;
        ++str2;
    }
    
    // Format output according to the interface of tests

    if (*str1 > *str2)
    {
        return 1;
    }
    else if (*str1 < *str2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
