
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "rb");

    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[512];

    FILE *image = NULL;

    char filename[8];

    int count = 0;

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (image != NULL)
            {
                fclose(image);
            }

            sprintf(filename, "%03i.jpg", count);

            image = fopen(filename, "wb");

            if (image == NULL)
            {
                fclose(card);
                return 1;
            }

            count++;
        }

        if (image != NULL)
        {
            fwrite(buffer, 1, 512, image);
        }
    }

    if (image != NULL)
    {
        fclose(image);
    }

    fclose(card);

    return 0;
}
