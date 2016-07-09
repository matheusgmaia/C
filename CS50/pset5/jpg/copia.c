/*
 * =====================================================================================
 *
 *       Filename:  recover.c
 *
 *    Description:  Program to recover jpegs from a memory card
 *
 *        Version:  1.0
 *        Created:  07/16/2011 07:47:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Adam Fowler (), me@adam-fowler.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>
#include <stdint.h>

typedef uint8_t  BYTE;
// function to test if first four bytes match pattern for jpeg 
bool isJpeg(BYTE buffer[])
{
      if((buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] == 224)||
    (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe1))
    {
        return true;
    }
    return false;
}

//function to name our files dynamically
FILE *make_file(int n)
{
        char filename[60];
        sprintf(filename, "0%i.jpg",n);
        FILE *out = fopen(filename, "w");
        if(out == NULL)
        {
            printf("Could not open %s for writing", filename);
            return NULL;
        }
        return out;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description: Recovers pictures from card.raw, solution to pset 5 from Harvard's CS50
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    
    // open file card.raw to read data
    FILE *fp = fopen("card.raw", "r");
    if(fp == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //int to hold value for sequential filenames 
    int num = 0;

    //allocate space for buffer to hold 512 byte blocks and next block
    BYTE buffer[512];
    
    //sequence through filenames and open files for writing
    while(fread(buffer, sizeof(BYTE), 512, fp) != 0)
    {
        while(isJpeg(buffer))
        {
            // create outfile 
            FILE *outfile = make_file(num);
            
            // write out jpeg to outfile
            fwrite(buffer, sizeof(BYTE), 512, outfile);
            
            // read next block checking for eof 
            if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                break;
            
            // while next block isnt the start of new jpeg keep writing
            while(!isJpeg(buffer))
            {
                fwrite(buffer, sizeof(BYTE), 512, outfile);
                if(fread(buffer, sizeof(BYTE), 512, fp) == 0)
                    break;
            }

            // close outfile 
            fclose(outfile);
            num++;
        }
        
    }
    // close file pointer 
    fclose(fp);
    return EXIT_SUCCESS;
}			
