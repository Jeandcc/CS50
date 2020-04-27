#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Checks the amount of Arguments and if the arguments are Positive Numbers
    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Stores the key
    int secretKey = atoi(argv[1]);

    //Gets string to be encrypted
    string plaintext = get_string("plaintext: ");

    //Loops through each character in the string
    for (int i = 0, plainTextLen = strlen(plaintext); i < plainTextLen; i++)
    {
        //Checks if it's an alpha character.
        if (isalpha(plaintext[i]))
        {
            //Converts into Ascii. "a" = 97 // "A" = 65
            int currentCharAscii = (int)plaintext[i];

            if (isupper(plaintext[i]))
            {
                plaintext[i] = 65 + ((currentCharAscii - 65) + secretKey) % 26;
            }
            else
            {
                plaintext[i] = 97 + ((currentCharAscii - 97) + secretKey) % 26;
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}