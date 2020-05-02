#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Checks for the presence of a second argument with the name of the target file
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Opens the file with the provided name
    FILE *file = fopen(argv[1], "r");

    //Checks if the file is readable or not
    if (file == NULL)
    {
        printf("Unsupported file provided.\n");
        return 1;
    }

    FILE *newFile;             //Initilize a var for new files that will be created
    unsigned char buffer[512]; //Initializes a buffer to read the chunks of the memory card
    bool isReadingJPG = false; //Initializes Bool condition that will be used in the loop
    char filename[9];          //Reserves enough space for future file names
    int foundFiles = 0;        //Updates the count of files found on the memory card

    // Keeps looping while it finds the expect amount of bytes (512)
    while (fread(buffer, 512, 1, file) == 1)
    {
        //Check if it's begning of JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (!isReadingJPG)
            {
                isReadingJPG = true;
            }

            else
            {
                // In case the previous image was already found, it closes the
                // currently open one so we can work with the newly-found JPG
                fclose(newFile);
            }

            sprintf(filename, "%03i.jpg", foundFiles); //Formats the filename
            newFile = fopen(filename, "w");            //Opens the new file that the JPG will be written to
            foundFiles++;                              //Updates the count of found files
        }

        if (isReadingJPG)
        {
            //Writes this chunk of data to the file that is currently being recovered
            fwrite(buffer, 512, 1, newFile);
        }
    }

    // Closes the stream of files
    fclose(file);
    fclose(newFile);

    return 0;
}
