#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


int main(int argc, string b[])
{
    
    for (int i=1; i<argc; i++)
    {
    int j=i;
    
    while (b[j]<b[(j-1)])
            {
            b[j]= b[(j-1)];
            
            (b[(j-1)]) = b[i];
            j--;
            }}
            for (int i=0; i<argc; i++)
            printf("%i", atoi(b[i]));
}
