#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string input = get_string("What's your name? \n");
    printf("Hello, %s\n", input);
}