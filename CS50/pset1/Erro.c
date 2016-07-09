nclude <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);
    
    if (argc != 2 || key<1)
    {
    printf("Usage: ./cesar1 (key)\n");
    return 0;
    }
    
    string p = GetString();
    int i;
    int n;
    for (int i = 0, n = strlen(p); i < n; i++)
    {
    printf("%c", (codigo[i]+key));
    }

}
