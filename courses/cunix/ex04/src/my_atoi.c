// Converts string to int
int my_atoi(const char *nptr)
{   
    int number = 0;
    int sign = 1;
    // Iterate over string char by char
    for (char ch = *nptr; ch != '\0'; ch = *(++nptr))
    {   
        // Parse minus sign
        if (ch == '-') 
        {
            sign = -1;
        }
        // Validate char
        else if (ch >= '0' && ch <= '9')
        {   
            // Convert digit to int
            number = number * 10 + ch - '0';
        }
        // If char is not valid stop parsing
        else 
        {   
            break;
        }

    }
    // Return signed number
    return number * sign;
}

