#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pixelToASCII(int pixelValue, int maxVal)
{
    char ascii[] = "@#S%?*+;:,."; // ASCII gradient
    int index = (pixelValue * (sizeof(ascii) - 2)) / maxVal;
    return ascii[index];
}

void convertToASCII(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    // Read image metadata
    char format[3];
    int width, height, maxVal;

    if (fscanf(file, "%2s", format) != 1 || strcmp(format, "P2") != 0)
    {
        printf("Unsupported file format or invalid header\n");
        fclose(file);
        return;
    }

    if (fscanf(file, "%d %d %d", &width, &height, &maxVal) != 3)
    {
        printf("Invalid image metadata\n");
        fclose(file);
        return;
    }

    // Debugging: Print image metadata
    printf("Image format: %s\n", format);
    printf("Width: %d, Height: %d, MaxVal: %d\n", width, height, maxVal);

    int pixel;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (fscanf(file, "%d", &pixel) != 1)
            {
                printf("Error reading pixel data\n");
                fclose(file);
                return;
            }

            // Display ASCII representation
            printf("%c", pixelToASCII(pixel, maxVal));
        }
        printf("\n");
    }

    fclose(file);
}

int main()
{
    char filename[256]; // Buffer to hold the filename

    // Prompt the user to enter the filename
    printf("Enter the image filename you want to convert to ASCII: ");
    fgets(filename, sizeof(filename), stdin);

    // Remove the newline character from the input, if present
    filename[strcspn(filename, "\n")] = 0;

    // Convert the provided PGM image to ASCII
    convertToASCII(filename);
    return 0;
}
