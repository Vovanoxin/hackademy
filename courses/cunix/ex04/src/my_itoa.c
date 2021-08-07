#include <stdlib.h>

// Max number of digits possible in 64-bit int with 10 base
#define MAX_INT_DIGITS_NUMBER 19

// Converts int to string
char *my_itoa(int nmb)
{   
    // Reserve array to store string. We add 2 because of '\0' and possible '-'
    char *number_str = malloc(MAX_INT_DIGITS_NUMBER + 2);
    unsigned int actual_size = 0;
    
    // Used to remember sign of input number
    int negative_flag = 0;
    
    // Get abs of number to work correctly with '%' operator 
    if (nmb < 0)
    {
        nmb = - nmb;
        negative_flag = 1;
    }
    
    // Get digits of number in reverse order
    do
    {
        number_str[actual_size++] = nmb % 10 + '0';
        nmb /= 10;
    }
    while (nmb != 0);
    
    // Add minus sign
    if (negative_flag) 
    {
        number_str[actual_size++] = '-';
    }
    
    number_str[actual_size] = '\0';

    // Reverse the string to get correct result
    for (int i = 0, j = actual_size - 1; i < j; i++, j--)
    {
        char temp = number_str[i];
        number_str[i] = number_str[j];
        number_str[j] = temp;
    }
    
    return number_str;
}

