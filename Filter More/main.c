#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0 ; i < height ; i ++) //making a loop to take values
    {
        for (int j = 0 ; j < width ; j ++)
        {
            int red = image[i][j].rgbtRed ;
            int blue = image[i][j].rgbtBlue ;
            int green = image[i][j].rgbtGreen ;

            int sum = red + blue + green ;  //WE take sum of each color for each pixel
            float avg = sum / 3.0 ;       // avg for them
            int grayscale = round(avg) ;


            image[i][j].rgbtBlue = grayscale ;   //we assign the new values one by one
            image[i][j].rgbtGreen = grayscale ;
            image[i][j].rgbtRed = grayscale ;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i ++)      // simple swipe algorithm
    {
        for (int j = 0 ; j < (width / 2) ; j ++) //making a loop to take values
        {
            int blue = image[i][width - 1 - j].rgbtBlue ;  //take first var.in new var
            int green = image[i][width - j - 1].rgbtGreen ;
            int red = image[i][width - j - 1].rgbtRed ;

            image[i][width - 1 - j].rgbtBlue = image[i][j].rgbtBlue ; //replace the two variables
            image[i][width - 1 - j].rgbtGreen = image[i][j].rgbtGreen ;
            image[i][width - 1 - j].rgbtRed = image[i][j].rgbtRed ;

            image[i][j].rgbtBlue = blue ; //return the first value to the second variable
            image[i][j].rgbtGreen = green ;
            image[i][j].rgbtRed = red ;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur[height][width] ; //create the matrix that will take the copy of main image

    for (int i = 0 ; i < height ; i ++) //making a loop to take values
    {
        for (int j = 0 ; j < width ; j ++) //making a nested loop to take values
        {
            blur[i][j].rgbtBlue = image[i][j].rgbtBlue ; //assign values of RBG of main images
            blur[i][j].rgbtGreen = image[i][j].rgbtGreen ;
            blur[i][j].rgbtRed = image[i][j].rgbtRed ;
        }
    }

    for (int h = 0 ; h < height ; h ++) //making a loop to take values
    {
        for (int w = 0 ; w < width ; w ++) //making a nested loop to take values
        {
            //top left corner
            if (h == 0 && w == 0)
            {
                int red = blur[h][w + 1].rgbtRed + blur[h + 1][w].rgbtRed + blur[h + 1][w + 1].rgbtRed + blur[h][w].rgbtRed   ;

                int avg_red = round(red / 4.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h][w + 1].rgbtBlue + blur[h + 1][w].rgbtBlue + blur[h + 1][w + 1].rgbtBlue + blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 4.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h][w + 1].rgbtGreen + blur[h + 1][w].rgbtGreen + blur[h + 1][w + 1].rgbtGreen + blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 4.0) ;

                image[h][w].rgbtGreen = avg_green ;
            } //top row
            else if (h == 0 && w != 0 && w != width - 1)
            {
                int red = blur[h][w - 1].rgbtRed + blur[h][w + 1].rgbtRed + blur[h + 1][w - 1].rgbtRed + blur[h + 1][w].rgbtRed + blur[h + 1][w +
                          1].rgbtRed + blur[h][w].rgbtRed   ;

                int avg_red = round(red / 6.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h][w - 1].rgbtBlue + blur[h][w + 1].rgbtBlue + blur[h + 1][w - 1].rgbtBlue + blur[h + 1][w].rgbtBlue + blur[h + 1][w
                           +
                           1].rgbtBlue + blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 6.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h][w - 1].rgbtGreen + blur[h][w + 1].rgbtGreen + blur[h + 1][w - 1].rgbtGreen + blur[h + 1][w].rgbtGreen + blur[h +
                            1][w +
                               1].rgbtGreen + blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 6.0) ;

                image[h][w].rgbtGreen = avg_green ;
            } //top right corner
            else if (h == 0 && w == width - 1)
            {
                int red = blur[h][w - 1].rgbtRed + blur[h + 1][w - 1].rgbtRed + blur[h + 1][w].rgbtRed + blur[h][w].rgbtRed   ;

                int avg_red = round(red / 4.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h][w - 1].rgbtBlue + blur[h + 1][w - 1].rgbtBlue + blur[h + 1][w].rgbtBlue + blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 4.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h][w - 1].rgbtGreen + blur[h + 1][w - 1].rgbtGreen + blur[h + 1][w].rgbtGreen + blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 4.0) ;

                image[h][w].rgbtGreen = avg_green ;
            } //left column
            else if (h != 0 && h != height - 1 && w == 0)
            {
                int red = blur[h - 1][w].rgbtRed + blur[h - 1][w + 1].rgbtRed + blur[h][w + 1].rgbtRed + blur[h + 1][w].rgbtRed + blur[h + 1][w +
                          1].rgbtRed + blur[h][w].rgbtRed   ;

                int avg_red = round(red / 6.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h - 1][w].rgbtBlue + blur[h - 1][w + 1].rgbtBlue + blur[h][w + 1].rgbtBlue + blur[h + 1][w].rgbtBlue + blur[h + 1][w
                           + 1].rgbtBlue + blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 6.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h - 1][w].rgbtGreen + blur[h - 1][w + 1].rgbtGreen + blur[h][w + 1].rgbtGreen + blur[h + 1][w].rgbtGreen + blur[h +
                            1][w + 1].rgbtGreen + blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 6.0) ;

                image[h][w].rgbtGreen = avg_green ;
            } //bottom left corner
            else if (h == height - 1 && w == 0)
            {
                int red = blur[h - 1][w].rgbtRed + blur[h - 1][w + 1].rgbtRed + blur[h][w + 1].rgbtRed + blur[h][w].rgbtRed   ;

                int avg_red = round(red / 4.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h - 1][w].rgbtBlue + blur[h - 1][w + 1].rgbtBlue + blur[h][w + 1].rgbtBlue + blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 4.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h - 1][w].rgbtGreen + blur[h - 1][w + 1].rgbtGreen + blur[h][w + 1].rgbtGreen + blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 4.0) ;

                image[h][w].rgbtGreen = avg_green ;
            } //bottom row (last one)
            else if (h == height - 1 && w != 0 && w != width - 1)
            {
                int red = blur[h - 1][w - 1].rgbtRed + blur[h - 1][w].rgbtRed + blur[h - 1][w + 1].rgbtRed + blur[h][w - 1].rgbtRed + blur[h][w +
                          1].rgbtRed +
                          blur[h][w].rgbtRed   ;

                int avg_red = round(red / 6.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h - 1][w - 1].rgbtBlue + blur[h - 1][w].rgbtBlue + blur[h - 1][w + 1].rgbtBlue + blur[h][w - 1].rgbtBlue + blur[h][w
                           +
                           1].rgbtBlue +
                           blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 6.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h - 1][w - 1].rgbtGreen + blur[h - 1][w].rgbtGreen + blur[h - 1][w + 1].rgbtGreen + blur[h][w - 1].rgbtGreen +
                            blur[h][w + 1].rgbtGreen +
                            blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 6.0) ;

                image[h][w].rgbtGreen = avg_green ;
            } //right bottom corner
            else if (h == height - 1 && w == width - 1)
            {
                int red = blur[h - 1][w - 1].rgbtRed + blur[h - 1][w].rgbtRed + blur[h][w - 1].rgbtRed + blur[h][w].rgbtRed   ;

                int avg_red = round(red / 4.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h - 1][w - 1].rgbtBlue + blur[h - 1][w].rgbtBlue + blur[h][w - 1].rgbtBlue + blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 4.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h - 1][w - 1].rgbtGreen + blur[h - 1][w].rgbtGreen + blur[h][w - 1].rgbtGreen +  blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 4.0) ;

                image[h][w].rgbtGreen = avg_green ;
            }  //right column
            else if (h != 0 && h != height - 1 && w == width - 1)
            {
                int red = blur[h - 1][w - 1].rgbtRed + blur[h - 1][w].rgbtRed + blur[h][w - 1].rgbtRed +
                          blur[h + 1][w - 1].rgbtRed + blur[h + 1][w].rgbtRed +  blur[h][w].rgbtRed   ;

                int avg_red = round(red / 6.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h - 1][w - 1].rgbtBlue + blur[h - 1][w].rgbtBlue + blur[h][w - 1].rgbtBlue +
                           blur[h + 1][w - 1].rgbtBlue + blur[h + 1][w].rgbtBlue +  blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 6.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h - 1][w - 1].rgbtGreen + blur[h - 1][w].rgbtGreen + blur[h][w - 1].rgbtGreen +
                            blur[h + 1][w - 1].rgbtGreen + blur[h + 1][w].rgbtGreen + blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 6.0) ;

                image[h][w].rgbtGreen = avg_green ;
            } //all other pixels that don't want special treatment
            else
            {
                int red = blur[h - 1][w - 1].rgbtRed + blur[h - 1][w].rgbtRed + blur[h - 1][w + 1].rgbtRed + blur[h][w - 1].rgbtRed + blur[h][w +
                          1].rgbtRed +
                          blur[h + 1][w - 1].rgbtRed + blur[h + 1][w].rgbtRed + blur[h + 1][w + 1].rgbtRed + blur[h][w].rgbtRed   ;

                int avg_red = round(red / 9.0) ;

                image[h][w].rgbtRed = avg_red ;


                int blue = blur[h - 1][w - 1].rgbtBlue + blur[h - 1][w].rgbtBlue + blur[h - 1][w + 1].rgbtBlue + blur[h][w - 1].rgbtBlue + blur[h][w
                           + 1].rgbtBlue +
                           blur[h + 1][w - 1].rgbtBlue + blur[h + 1][w].rgbtBlue + blur[h + 1][w + 1].rgbtBlue + blur[h][w].rgbtBlue  ;

                int avg_blue = round(blue / 9.0) ;

                image[h][w].rgbtBlue = avg_blue ;


                int green = blur[h - 1][w - 1].rgbtGreen + blur[h - 1][w].rgbtGreen + blur[h - 1][w + 1].rgbtGreen + blur[h][w - 1].rgbtGreen +
                            blur[h][w + 1].rgbtGreen +
                            blur[h + 1][w - 1].rgbtGreen + blur[h + 1][w].rgbtGreen + blur[h + 1][w + 1].rgbtGreen + blur[h][w].rgbtGreen  ;

                int avg_green = round(green / 9.0) ;

                image[h][w].rgbtGreen = avg_green ;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imgCopy[height][width];

    float gxRed;
    float gxGreen; //create new variables for gx
    float gxBlue;

    float gyRed; //create new variables for gy
    float gyGreen;
    float gyBlue;

    float gRed;  //the sqrt of their power2
    float gGreen;
    float gBlue;



    for (int h = 0; h < height; h++) //making a loop to take values
    {
        for (int w = 0; w < width; w++) //making a nested loop to take values
        {
            imgCopy[h][w].rgbtRed = image[h][w].rgbtRed; //make a copy matrix of the main image
            imgCopy[h][w].rgbtGreen = image[h][w].rgbtGreen;
            imgCopy[h][w].rgbtBlue = image[h][w].rgbtBlue;
        }
    }

    for (int h = 0; h < height; h++) //making a loop to take values
    {
        for (int w = 0; w < width; w++) //making a nested loop to take values
        {


            // Top left Corner
            if (h == 0 && w == 0)
            {
                // For Gx and Gy values imagine a 3x3 matrix at the corner and any pixel outside the corner is considered to be equal zero
                //(The corner pixels does not equal 0 you treat the corner pixel as a 3x3 matrix same as the middle pixels and get the Gx and Gy values for them)
                gxRed = 2 * imgCopy[h][w + 1].rgbtRed + imgCopy[h + 1][w + 1].rgbtRed;
                gxGreen = 2 * imgCopy[h][w + 1].rgbtGreen + imgCopy[h + 1][w + 1].rgbtGreen;
                gxBlue = 2 * imgCopy[h][w + 1].rgbtBlue + imgCopy[h + 1][w + 1].rgbtBlue;

                gyRed = 2 * imgCopy[h + 1][w].rgbtRed + imgCopy[h + 1][w + 1].rgbtRed ;
                gyGreen = 2 * imgCopy[h + 1][w].rgbtGreen + imgCopy[h + 1][w + 1].rgbtGreen;
                gyBlue = 2 * imgCopy[h + 1][w].rgbtBlue + imgCopy[h + 1][w + 1].rgbtBlue;

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Top-right corner
            else if (h == 0 && w == width - 1)
            {
                gxRed = -2 * imgCopy[h][w - 1].rgbtRed + -1 * imgCopy[h + 1][w - 1].rgbtRed;
                gxGreen = -2 * imgCopy[h][w - 1].rgbtGreen + -1 * imgCopy[h + 1][w - 1].rgbtGreen;
                gxBlue = -2 * imgCopy[h][w - 1].rgbtBlue + -1 * imgCopy[h + 1][w - 1].rgbtBlue;

                gyRed = 2 * imgCopy[h + 1][w].rgbtRed + imgCopy[h + 1][w - 1].rgbtRed;
                gyGreen = 2 * imgCopy[h + 1][w].rgbtGreen + imgCopy[h + 1][w - 1].rgbtGreen;
                gyBlue = 2 * imgCopy[h + 1][w].rgbtBlue + imgCopy[h + 1][w - 1].rgbtBlue;

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Bottom left corner
            else if (h == height - 1 && w == 0)
            {
                gxRed = 1 * imgCopy[h - 1][w + 1].rgbtRed + 2 * imgCopy[h][w + 1].rgbtRed;
                gxGreen = 1 * imgCopy[h - 1][w + 1].rgbtGreen + 2 * imgCopy[h][w + 1].rgbtGreen;
                gxBlue = 1 * imgCopy[h - 1][w + 1].rgbtBlue + 2 * imgCopy[h][w + 1].rgbtBlue;

                gyRed = -1 * imgCopy[h - 1][w + 1].rgbtRed + -2 * imgCopy[h - 1][w].rgbtRed;
                gyGreen = -1 * imgCopy[h - 1][w + 1].rgbtGreen + -2 * imgCopy[h - 1][w].rgbtGreen;
                gyBlue = -1 * imgCopy[h - 1][w + 1].rgbtBlue + -2 * imgCopy[h - 1][w].rgbtBlue;

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Bottom-right corner
            else if (h == height - 1 && w == width - 1)
            {
                gxRed = -1 * imgCopy[h - 1][w - 1].rgbtRed + -2 * imgCopy[h][w - 1].rgbtRed;
                gxGreen = -1 * imgCopy[h - 1][w - 1].rgbtGreen + -2 * imgCopy[h][w - 1].rgbtGreen;
                gxBlue = -1 * imgCopy[h - 1][w - 1].rgbtBlue + -2 * imgCopy[h][w - 1].rgbtBlue;

                gyRed = -1 * imgCopy[h - 1][w - 1].rgbtRed + -2 * imgCopy[h - 1][w].rgbtRed;
                gyGreen = -1 * imgCopy[h - 1][w - 1].rgbtGreen + -2 * imgCopy[h - 1][w].rgbtGreen;
                gyBlue = -1 * imgCopy[h - 1][w - 1].rgbtBlue + -2 * imgCopy[h - 1][w].rgbtBlue;

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Top row pixels
            else if (h == 0 && w != 0 && w != width - 1)
            {
                gxRed = (float)((-2 * imgCopy[h][w - 1].rgbtRed)     + (0 * imgCopy[h][w].rgbtRed)     + (2 * imgCopy[h][w + 1].rgbtRed) +
                                (-1 * imgCopy[h + 1][w - 1].rgbtRed) + (0 * imgCopy[h + 1][w].rgbtRed) + (1 * imgCopy[h + 1][w + 1].rgbtRed));

                gxGreen = (float)((-2 * imgCopy[h][w - 1].rgbtGreen)     + (0 * imgCopy[h][w].rgbtGreen)     + (2 * imgCopy[h][w + 1].rgbtGreen) +
                                  (-1 * imgCopy[h + 1][w - 1].rgbtGreen) + (0 * imgCopy[h + 1][w].rgbtGreen) + (1 * imgCopy[h + 1][w + 1].rgbtGreen));

                gxBlue = (float)((-2 * imgCopy[h][w - 1].rgbtBlue)     + (0 * imgCopy[h][w].rgbtBlue)     + (2 * imgCopy[h][w + 1].rgbtBlue) +
                                 (-1 * imgCopy[h + 1][w - 1].rgbtBlue) + (0 * imgCopy[h + 1][w].rgbtBlue) + (1 * imgCopy[h + 1][w + 1].rgbtBlue));

                gyRed = (float)((0 * imgCopy[h][w - 1].rgbtRed)      + (0 * imgCopy[h][w].rgbtRed)      + (0 * imgCopy[h][w + 1].rgbtRed) +
                                (1 * imgCopy[h + 1][w - 1].rgbtRed)  + (2 * imgCopy[h + 1][w].rgbtRed)  + (1 * imgCopy[h + 1][w + 1].rgbtRed));

                gyGreen = (float)((0 * imgCopy[h][w - 1].rgbtGreen)      + (0 * imgCopy[h][w].rgbtGreen)       + (0 * imgCopy[h][w + 1].rgbtGreen) +
                                  (1 * imgCopy[h + 1][w - 1].rgbtGreen)  + (2 * imgCopy[h + 1][w].rgbtGreen)   + (1 * imgCopy[h + 1][w + 1].rgbtGreen));

                gyBlue = (float)((0 * imgCopy[h][w - 1].rgbtBlue)      + (0 * imgCopy[h][w].rgbtBlue)       + (0 * imgCopy[h][w + 1].rgbtBlue) +
                                 (1 * imgCopy[h + 1][w - 1].rgbtBlue)  + (2 * imgCopy[h + 1][w].rgbtBlue)   + (1 * imgCopy[h + 1][w + 1].rgbtBlue));

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Bottom row pixels
            else if (h == height - 1 && w != 0 && w != width - 1)
            {
                gxRed = (float)((-1 * imgCopy[h - 1][w - 1].rgbtRed) + (0 * imgCopy[h - 1][w].rgbtRed) + (1 * imgCopy[h - 1][w + 1].rgbtRed) +
                                (-2 * imgCopy[h][w - 1].rgbtRed)     + (0 * imgCopy[h][w].rgbtRed)     + (2 * imgCopy[h][w + 1].rgbtRed));

                gxGreen = (float)((-1 * imgCopy[h - 1][w - 1].rgbtGreen) + (0 * imgCopy[h - 1][w].rgbtGreen) +
                                  (1 * imgCopy[h - 1][w + 1].rgbtGreen) +
                                  (-2 * imgCopy[h][w - 1].rgbtGreen)     + (0 * imgCopy[h][w].rgbtGreen)     + (2 * imgCopy[h][w + 1].rgbtGreen));

                gxBlue = (float)((-1 * imgCopy[h - 1][w - 1].rgbtBlue) + (0 * imgCopy[h - 1][w].rgbtBlue) + (1 * imgCopy[h - 1][w + 1].rgbtBlue) +
                                 (-2 * imgCopy[h][w - 1].rgbtBlue)     + (0 * imgCopy[h][w].rgbtBlue)     + (2 * imgCopy[h][w + 1].rgbtBlue));

                gyRed = (float)((-1 * imgCopy[h - 1][w - 1].rgbtRed) + (-2 * imgCopy[h - 1][w].rgbtRed) + (-1 * imgCopy[h - 1][w + 1].rgbtRed) +
                                (0 * imgCopy[h][w - 1].rgbtRed)      + (0 * imgCopy[h][w].rgbtRed)      + (0 * imgCopy[h][w + 1].rgbtRed));

                gyGreen = (float)((-1 * imgCopy[h - 1][w - 1].rgbtGreen) + (-2 * imgCopy[h - 1][w].rgbtGreen)  +
                                  (-1 * imgCopy[h - 1][w + 1].rgbtGreen) +
                                  (0 * imgCopy[h][w - 1].rgbtGreen)      + (0 * imgCopy[h][w].rgbtGreen)       + (0 * imgCopy[h][w + 1].rgbtGreen));

                gyBlue = (float)((-1 * imgCopy[h - 1][w - 1].rgbtBlue) + (-2 * imgCopy[h - 1][w].rgbtBlue)  +
                                 (-1 * imgCopy[h - 1][w + 1].rgbtBlue) +
                                 (0 * imgCopy[h][w - 1].rgbtBlue)      + (0 * imgCopy[h][w].rgbtBlue)       + (0 * imgCopy[h][w + 1].rgbtBlue));

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Left-side column pixels
            else if (h != 0 && h != height - 1 && w == 0)
            {
                gxRed = (float)((0 * imgCopy[h - 1][w].rgbtRed) + (1 * imgCopy[h - 1][w + 1].rgbtRed) +
                                (0 * imgCopy[h][w].rgbtRed)     + (2 * imgCopy[h][w + 1].rgbtRed) +
                                (0 * imgCopy[h + 1][w].rgbtRed) + (1 * imgCopy[h + 1][w + 1].rgbtRed));

                gxGreen = (float)((0 * imgCopy[h - 1][w].rgbtGreen) + (1 * imgCopy[h - 1][w + 1].rgbtGreen) +
                                  (0 * imgCopy[h][w].rgbtGreen)     + (2 * imgCopy[h][w + 1].rgbtGreen) +
                                  (0 * imgCopy[h + 1][w].rgbtGreen) + (1 * imgCopy[h + 1][w + 1].rgbtGreen));

                gxBlue = (float)((0 * imgCopy[h - 1][w].rgbtBlue) + (1 * imgCopy[h - 1][w + 1].rgbtBlue) +
                                 (0 * imgCopy[h][w].rgbtBlue)     + (2 * imgCopy[h][w + 1].rgbtBlue) +
                                 (0 * imgCopy[h + 1][w].rgbtBlue) + (1 * imgCopy[h + 1][w + 1].rgbtBlue));

                gyRed = (float)((-2 * imgCopy[h - 1][w].rgbtRed) + (-1 * imgCopy[h - 1][w + 1].rgbtRed) +
                                (0 * imgCopy[h][w].rgbtRed)      + (0 * imgCopy[h][w + 1].rgbtRed) +
                                (2 * imgCopy[h + 1][w].rgbtRed)  + (1 * imgCopy[h + 1][w + 1].rgbtRed));

                gyGreen = (float)((-2 * imgCopy[h - 1][w].rgbtGreen)  + (-1 * imgCopy[h - 1][w + 1].rgbtGreen) +
                                  (0 * imgCopy[h][w].rgbtGreen)       + (0 * imgCopy[h][w + 1].rgbtGreen) +
                                  (2 * imgCopy[h + 1][w].rgbtGreen)   + (1 * imgCopy[h + 1][w + 1].rgbtGreen));

                gyBlue = (float)((-2 * imgCopy[h - 1][w].rgbtBlue)  + (-1 * imgCopy[h - 1][w + 1].rgbtBlue) +
                                 (0 * imgCopy[h][w].rgbtBlue)       + (0 * imgCopy[h][w + 1].rgbtBlue) +
                                 (2 * imgCopy[h + 1][w].rgbtBlue)   + (1 * imgCopy[h + 1][w + 1].rgbtBlue));

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Right-side corner pixels
            else if (h != 0 && h != height - 1 && w == width - 1)
            {
                gxRed = (float)((-1 * imgCopy[h - 1][w - 1].rgbtRed) + (0 * imgCopy[h - 1][w].rgbtRed) +
                                (-2 * imgCopy[h][w - 1].rgbtRed)     + (0 * imgCopy[h][w].rgbtRed)     +
                                (-1 * imgCopy[h + 1][w - 1].rgbtRed) + (0 * imgCopy[h + 1][w].rgbtRed));

                gxGreen = (float)((-1 * imgCopy[h - 1][w - 1].rgbtGreen) + (0 * imgCopy[h - 1][w].rgbtGreen) +
                                  (-2 * imgCopy[h][w - 1].rgbtGreen)     + (0 * imgCopy[h][w].rgbtGreen)     +
                                  (-1 * imgCopy[h + 1][w - 1].rgbtGreen) + (0 * imgCopy[h + 1][w].rgbtGreen));

                gxBlue = (float)((-1 * imgCopy[h - 1][w - 1].rgbtBlue) + (0 * imgCopy[h - 1][w].rgbtBlue) +
                                 (-2 * imgCopy[h][w - 1].rgbtBlue)     + (0 * imgCopy[h][w].rgbtBlue)     +
                                 (-1 * imgCopy[h + 1][w - 1].rgbtBlue) + (0 * imgCopy[h + 1][w].rgbtBlue));

                gyRed = (float)((-1 * imgCopy[h - 1][w - 1].rgbtRed) + (-2 * imgCopy[h - 1][w].rgbtRed) +
                                (0 * imgCopy[h][w - 1].rgbtRed)      + (0 * imgCopy[h][w].rgbtRed)      +
                                (1 * imgCopy[h + 1][w - 1].rgbtRed)  + (2 * imgCopy[h + 1][w].rgbtRed));

                gyGreen = (float)((-1 * imgCopy[h - 1][w - 1].rgbtGreen) + (-2 * imgCopy[h - 1][w].rgbtGreen)  +
                                  (0 * imgCopy[h][w - 1].rgbtGreen)      + (0 * imgCopy[h][w].rgbtGreen)       +
                                  (1 * imgCopy[h + 1][w - 1].rgbtGreen)  + (2 * imgCopy[h + 1][w].rgbtGreen));

                gyBlue = (float)((-1 * imgCopy[h - 1][w - 1].rgbtBlue) + (-2 * imgCopy[h - 1][w].rgbtBlue)  +
                                 (0 * imgCopy[h][w - 1].rgbtBlue)      + (0 * imgCopy[h][w].rgbtBlue)       +
                                 (1 * imgCopy[h + 1][w - 1].rgbtBlue)  + (2 * imgCopy[h + 1][w].rgbtBlue));

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }

            // Middle 3x3 pixels
            else
            {
                gxRed = (float)((-1 * imgCopy[h - 1][w - 1].rgbtRed) + (0 * imgCopy[h - 1][w].rgbtRed) +
                                (1 * imgCopy[h - 1][w + 1].rgbtRed) +
                                (-2 * imgCopy[h][w - 1].rgbtRed)     + (0 * imgCopy[h][w].rgbtRed)     + (2 * imgCopy[h][w + 1].rgbtRed) +
                                (-1 * imgCopy[h + 1][w - 1].rgbtRed) + (0 * imgCopy[h + 1][w].rgbtRed) + (1 * imgCopy[h + 1][w + 1].rgbtRed));

                gxGreen = (float)((-1 * imgCopy[h - 1][w - 1].rgbtGreen) + (0 * imgCopy[h - 1][w].rgbtGreen) +
                                  (1 * imgCopy[h - 1][w + 1].rgbtGreen) +
                                  (-2 * imgCopy[h][w - 1].rgbtGreen)     + (0 * imgCopy[h][w].rgbtGreen)     + (2 * imgCopy[h][w + 1].rgbtGreen) +
                                  (-1 * imgCopy[h + 1][w - 1].rgbtGreen) + (0 * imgCopy[h + 1][w].rgbtGreen) + (1 * imgCopy[h + 1][w + 1].rgbtGreen));

                gxBlue = (float)((-1 * imgCopy[h - 1][w - 1].rgbtBlue) + (0 * imgCopy[h - 1][w].rgbtBlue) +
                                 (1 * imgCopy[h - 1][w + 1].rgbtBlue) +
                                 (-2 * imgCopy[h][w - 1].rgbtBlue)     + (0 * imgCopy[h][w].rgbtBlue)     + (2 * imgCopy[h][w + 1].rgbtBlue) +
                                 (-1 * imgCopy[h + 1][w - 1].rgbtBlue) + (0 * imgCopy[h + 1][w].rgbtBlue) + (1 * imgCopy[h + 1][w + 1].rgbtBlue));

                gyRed = (float)((-1 * imgCopy[h - 1][w - 1].rgbtRed) + (-2 * imgCopy[h - 1][w].rgbtRed) +
                                (-1 * imgCopy[h - 1][w + 1].rgbtRed) +
                                (0 * imgCopy[h][w - 1].rgbtRed)      + (0 * imgCopy[h][w].rgbtRed)      + (0 * imgCopy[h][w + 1].rgbtRed) +
                                (1 * imgCopy[h + 1][w - 1].rgbtRed)  + (2 * imgCopy[h + 1][w].rgbtRed)  + (1 * imgCopy[h + 1][w + 1].rgbtRed));

                gyGreen = (float)((-1 * imgCopy[h - 1][w - 1].rgbtGreen) + (-2 * imgCopy[h - 1][w].rgbtGreen)  +
                                  (-1 * imgCopy[h - 1][w + 1].rgbtGreen) +
                                  (0 * imgCopy[h][w - 1].rgbtGreen)      + (0 * imgCopy[h][w].rgbtGreen)       + (0 * imgCopy[h][w + 1].rgbtGreen) +
                                  (1 * imgCopy[h + 1][w - 1].rgbtGreen)  + (2 * imgCopy[h + 1][w].rgbtGreen)   + (1 * imgCopy[h + 1][w + 1].rgbtGreen));

                gyBlue = (float)((-1 * imgCopy[h - 1][w - 1].rgbtBlue) + (-2 * imgCopy[h - 1][w].rgbtBlue)  +
                                 (-1 * imgCopy[h - 1][w + 1].rgbtBlue) +
                                 (0 * imgCopy[h][w - 1].rgbtBlue)      + (0 * imgCopy[h][w].rgbtBlue)       + (0 * imgCopy[h][w + 1].rgbtBlue) +
                                 (1 * imgCopy[h + 1][w - 1].rgbtBlue)  + (2 * imgCopy[h + 1][w].rgbtBlue)   + (1 * imgCopy[h + 1][w + 1].rgbtBlue));

                gRed = sqrt((gxRed * gxRed) + (gyRed * gyRed));
                gGreen = sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen));
                gBlue = sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue));

                gRed = round(gRed);
                gGreen = round(gGreen);
                gBlue = round(gBlue);

                if (gRed > 255)
                {
                    gRed = 255;
                }
                if (gGreen > 255)
                {
                    gGreen = 255;
                }
                if (gBlue > 255)
                {
                    gBlue = 255;
                }
                image[h][w].rgbtRed = gRed;
                image[h][w].rgbtGreen = gGreen;
                image[h][w].rgbtBlue = gBlue;
            }
        }

    }
    return;
}
