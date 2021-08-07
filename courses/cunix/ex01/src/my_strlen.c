// Takes c-style string and returns its length
unsigned int my_strlen(char *str)
{
    unsigned int counter = 0;
    
    // Iterate string till null char
    while (str[counter] != '\0')
    {
        ++counter;
    }
    return counter;
}
