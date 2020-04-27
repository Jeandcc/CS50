#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loops through all the pixels in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE current = image[i][j];
            // Takes the average amount of R and G and B from a pixel
            int average = round(((float)current.rgbtBlue + (float)current.rgbtGreen + (float)current.rgbtRed) / (float)3);

            // Applies the found average eto to all the three channels
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        /// Loops run until the horizontal middle of the image
        for (int j = 0; j < floor(width / 2); j++)
        {
            // Temporary var to store a "moving" value
            RGBTRIPLE tempLeft = image[i][j];

            // Swaps pixels from the left with the ones from the right
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tempLeft;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copies the image in order to keep the original values
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            copy[i][h] = image[i][h];
        }
    }
    // Loops through all the pixels of the picture, Left -> Righ, Top -> Bottom
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Rcumulator = 0;
            int Gcumulator = 0;
            int Bcumulator = 0;
            int divisor = 0;
            int blurRadius = 1;

            // Loops through all the neighboring pixels according to the set blur radius.
            for (int x = 0 - blurRadius; x <= blurRadius; x++)
            {
                // Loops through the columns
                for (int y = 0 - blurRadius; y <= blurRadius; y++)
                {
                    // Checks if determined pixel is within bounds
                    if (y + j < 0 || y + j >= width || x + i < 0 || x + i >= height)
                    {
                        //If Pixel doesn't exist, moves to the next iteration
                        continue;
                    }
                    //Adds the values to a acumulator that will be used to average things out
                    divisor++;
                    Bcumulator += copy[x + i][y + j].rgbtBlue;
                    Gcumulator += copy[x + i][y + j].rgbtGreen;
                    Rcumulator += copy[x + i][y + j].rgbtRed;
                }
            }
            // Performs the calculation of average
            image[i][j].rgbtBlue = round((float)Bcumulator / (float)divisor);
            image[i][j].rgbtGreen = round((float)Gcumulator / (float)divisor);
            image[i][j].rgbtRed = round((float)Rcumulator / (float)divisor);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int graphRadius = 1;

    // Copies the original image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            copy[i][h] = image[i][h];
        }
    }
    // Loops through all the pixels of the picture, Left -> Righ, Top -> Bottom
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initializes the values for the Convulational Matrix
            int redGx = 0;
            int blueGx = 0;
            int greenGx = 0;
            int redGy = 0;
            int blueGy = 0;
            int greenGy = 0;
            int gxWeight = 0;
            int gyWeight = 0;

            // Loops through all the neighboring pixels according to the set blur radius.
            for (int x = 0 - graphRadius; x <= graphRadius; x++)
            {
                // Loops through the columns
                for (int y = 0 - graphRadius; y <= graphRadius; y++)
                {
                    // Checks if determined pixel is within bounds
                    if (y + j < 0 || y + j >= width || x + i < 0 || x + i >= height)
                    {
                        continue;
                    }

                    // Sets the weight for Gx and Gy accordingly to the relative
                    // position of the pixel to be tested
                    if (x == -1 && y == -1)
                    {
                        gxWeight = -1;
                        gyWeight = -1;
                    }
                    else if (x == -1 && y == 0)
                    {
                        gxWeight = 0;
                        gyWeight = -2;
                    }
                    else if (x == -1 && y == 1)
                    {
                        gxWeight = 1;
                        gyWeight = -1;
                    }
                    else if (x == 0 && y == -1)
                    {
                        gxWeight = -2;
                        gyWeight = 0;
                    }
                    else if (x == 0 && y == 0)
                    {
                        gxWeight = 0;
                        gyWeight = 0;
                    }
                    else if (x == 0 && y == 1)
                    {
                        gxWeight = 2;
                        gyWeight = 0;
                    }
                    else if (x == 1 && y == -1)
                    {
                        gxWeight = -1;
                        gyWeight = 1;
                    }
                    else if (x == 1 && y == 0)
                    {
                        gxWeight = 0;
                        gyWeight = 2;
                    }
                    else if (x == 1 && y == 1)
                    {
                        gxWeight = 1;
                        gyWeight = 1;
                    }

                    // Updates the values to their respectitive chanels
                    redGx += (copy[x + i][y + j].rgbtRed * gxWeight);
                    blueGx += (copy[x + i][y + j].rgbtBlue * gxWeight);
                    greenGx += (copy[x + i][y + j].rgbtGreen * gxWeight);
                    redGy += (copy[x + i][y + j].rgbtRed * gyWeight);
                    blueGy += (copy[x + i][y + j].rgbtBlue * gyWeight);
                    greenGy += (copy[x + i][y + j].rgbtGreen * gyWeight);
                }
            }

            // Changes the color channels to the new values using Sobel operator
            image[i][j].rgbtBlue = fmin(round(sqrt(pow(blueGx, 2) + pow(blueGy, 2))), 255);
            image[i][j].rgbtGreen = fmin(round(sqrt(pow(greenGx, 2) + pow(greenGy, 2))), 255);
            image[i][j].rgbtRed = fmin(round(sqrt(pow(redGx, 2) + pow(redGy, 2))), 255);
        }
    }
    return;
}
