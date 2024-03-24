#include "helpers.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen
            + image[i][j].rgbtRed) / (BYTE) 3;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

void neighbors_average(int height, int width, RGBTRIPLE **blurred, RGBTRIPLE (*image)[width], int i, int j)
{
    int sum_red = 0;
    int sum_green = 0;
    int sum_blue = 0;

    int n = 0;

    int r_start = (i - 1 >= 0) ? i - 1 : i;
    int r_end = (i + 1 < height) ? i + 1 : i;
    int c_start = (j - 1 >= 0) ? j - 1 : j;
    int c_end = (j + 1 < width) ? j + 1 : j;

    for (int r = r_start; r <= r_end; r++)
    {
        for (int c = c_start; c <= c_end; c++)
        {
            sum_red += (int)image[r][c].rgbtRed;
            sum_green += (int)image[r][c].rgbtGreen;
            sum_blue += (int)image[r][c].rgbtBlue;
            n++;
        }
    }

    blurred[i][j].rgbtRed = (BYTE)(sum_red / n);
    blurred[i][j].rgbtGreen = (BYTE)(sum_green / n);
    blurred[i][j].rgbtBlue = (BYTE)(sum_blue / n);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE **blurred = malloc(height * sizeof(RGBTRIPLE *));
    for (int i = 0; i < height; i++)
    {
        blurred[i] = malloc(width * sizeof(RGBTRIPLE));
        for (int j = 0; j < width; j++)
        {
            neighbors_average(height, width, blurred, image, i, j);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurred[i][j];
        }
        free(blurred[i]);
    }

    free(blurred);
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int Gx_red, Gx_green, Gx_blue;
    int Gy_red, Gy_green, Gy_blue;

    int G_red, G_green, G_blue;

    int Gx_kernel[3][3] = {{-1, 0, 1},
                           {-2, 0, 2},
                           {-1, 0, 1}};

    int Gy_kernel[3][3] = {{-1, -2, -1},
                           {0, 0, 0},
                           {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Gx_red = Gx_green = Gx_blue = 0;
            Gy_red = Gy_green = Gy_blue = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;

                    if (row < 0 || row >= height || col < 0 || col >= width)
                    {
                        continue;
                    }

                    Gx_red += image[row][col].rgbtRed * Gx_kernel[k + 1][l + 1];
                    Gx_green += image[row][col].rgbtGreen * Gx_kernel[k + 1][l + 1];
                    Gx_blue += image[row][col].rgbtBlue * Gx_kernel[k + 1][l + 1];

                    Gy_red += image[row][col].rgbtRed * Gy_kernel[k + 1][l + 1];
                    Gy_green += image[row][col].rgbtGreen * Gy_kernel[k + 1][l + 1];
                    Gy_blue += image[row][col].rgbtBlue * Gy_kernel[k + 1][l + 1];
                }
            }

            G_red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            G_green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            G_blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            G_red = G_red > 255 ? 255 : G_red;
            G_green = G_green > 255 ? 255 : G_green;
            G_blue = G_blue > 255 ? 255 : G_blue;

            temp[i][j].rgbtRed = G_red;
            temp[i][j].rgbtGreen = G_green;
            temp[i][j].rgbtBlue = G_blue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}