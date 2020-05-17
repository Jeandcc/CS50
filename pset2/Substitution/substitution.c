#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isValidKey(string key);

int main(int argc, string argv[])
{
    //Checks the amount of Arguments and if the arguments are Positive Numbers
    if (argc != 2 || !isValidKey(argv[1]) || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution arguments\n");
        return 1;
    }

    //Stores the key
    char *secretKey = argv[1];

    //Gets string to be encrypted
    string plaintext = get_string("plaintext: ");

    //Loops through each character in the string
    for (int i = 0, plainTextLen = strlen(plaintext), asciiOffset = 0 ; i < plainTextLen; i++)
    {
        //Checks if it's an alpha character.
        if (isalpha(plaintext[i]))
        {
            // Performs the rotation of the char in a case sensitive way
            if (isupper(plaintext[i]))
            {
                asciiOffset = 65;
                int thisLetterIndex = (int) plaintext[i] - asciiOffset;
                plaintext[i] = toupper(secretKey[thisLetterIndex]);
            }
            else
            {
                asciiOffset = 97;
                int thisLetterIndex = (int) plaintext[i] - asciiOffset;
                plaintext[i] = tolower(secretKey[thisLetterIndex]);
            }
        }
    }
    //Returns the result
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

//Function that checks the validity of the key
bool isValidKey(string key)
{
    //Initizalizes an array that will store the occurrences of each character
    int chars [26] = { 0 };

    //Iterates through each char in the key
    for (int i = 0, keyLength = strlen(key); i < keyLength; i++)
    {
        //Checks if it's an alpha character
        if (!isalpha(key[i]))
        {
            return false;
        }

        //Prepares for the case-insensitive count of occurrences
        int upperOffset = (toupper(key[i])) - 65;

        //Checks if that character already occurred before in the key
        if (chars[upperOffset] != 0)
        {
            return false;
        }
        //Updates the ammount of occurences of that character
        chars[upperOffset] ++;

    }
    return true;
}