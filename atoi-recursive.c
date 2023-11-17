#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int count = strlen(input);

    //base case
    if (count == 0)
    {
        return 0;
    }

    else
    {
        //Gets the integer of the last digit
        int n = input[count - 1] - '0';

        //Remove last digit
        input[count - 1] = '\0';

        //Returns converted string as digit
        return n + 10 * convert(input);
    }
}