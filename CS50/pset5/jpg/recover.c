/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    BYTE buffer[512];
    FILE *file = fopen("card.raw", "r");
    int i = 0;
    
    while(fread(buffer, sizeof(BYTE), 512, file) != 0)
    {
    if((buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] == 224)||
    (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1))
        {   
        char title[60];
        sprintf (title, "%d.jpg", i);
        FILE* img = fopen(title, "a");
        fwrite(buffer, sizeof(BYTE), 512, img);
        i++;
        
        while((buffer[0] != 255 && buffer[1] != 216 && buffer[2] != 255 && buffer[3] != 224)||
    (buffer[0] != 0xff && buffer[1] != 0xd8 && buffer[2] != 0xff && buffer[3] != 0xe1))
        {
        fwrite(buffer, sizeof(BYTE), 512, img);
        }
        fclose (img);
        }
        }
}
