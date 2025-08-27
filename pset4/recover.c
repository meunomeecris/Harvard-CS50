y#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Create and allocate memory
    const int BLOCK = 512;
    const int BYTE = 8;
    uint8_t *buffer = malloc(BLOCK);
    if (buffer == NULL)
    {
        printf("Could not allocate memory for %s.\n", buffer);
        return 1;
    }

    char *filename = malloc(BYTE);
    if (filename == NULL)
    {
        printf("Could not allocate memory for %s.\n", filename);
        return 1;
    }

    // Keep count the images created
    int filename_count = 0;

    // Create a file for the each image that's start empty == NULL
    FILE *image = NULL;

    // Read all bytes inside the card and read 512 at the time saving inside the buffer
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if the accutal buffer is a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if is a new JEPG
            if (image == NULL)
            {
                // Create a file, add a name and write the block to the file
                sprintf(filename, "%03i.jpg", filename_count);
                image = fopen(filename, "w");
                fwrite(buffer, 512, 1, image);
                filename_count++;
            }
            // Close the old and open a new file for the next JPEG
            else
            {
                fclose(image);
                image = NULL;

                sprintf(filename, "%03i.jpg", filename_count);
                image = fopen(filename, "w");
                fwrite(buffer, 512, 1, image);
                filename_count++;
            }
        }
        // Case the BLOCK is not a beginder of a JPEG image, should keep adding the BLOCK to the
        // opened file
        else
        {
            if (image != NULL)
            {
                fwrite(buffer, 512, 1, image);
            }
        }
    }

    // Close files and clean memory
    fclose(card);
    fclose(image);
    free(filename);
    free(buffer);
    return 0;
}
