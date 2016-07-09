#include <cs50.h>
#include <stdio.h>
#include <string.h>
	
int main(void)
{
    int b = 2;
    printf("Please give me a string: ");
    string s = GetString();
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c\n", s[b]);
    }
}

