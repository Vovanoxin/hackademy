unsigned int my_strlen(char *str)
{
    unsigned int counter = 0;

    while (str[counter] != '\0')
    {
        ++counter;
    }
    return counter;
}
