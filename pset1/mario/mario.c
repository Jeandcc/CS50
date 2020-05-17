#include <cs50.h>
#include <stdio.h>

//Initializing Function
void printStr(int n, string digit);

int main(void)
{
    int size;
    do 
    {
        //Prompts the user the height of the pyramid
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    for (int i = 1; i <= size; i++)
    {
        printStr(size - i, " "); // Whitespace to the left of the pound
        printStr(i, "#");
        printStr(2, " "); // Space between the pyramid
        printStr(i, "#");
        printf("\n"); // New Line
    }
}
/*
* param(n) == Number of times to print a given string
* param(digit) == String to be print
*/
void printStr(int n, string digit)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", digit);
    }
};