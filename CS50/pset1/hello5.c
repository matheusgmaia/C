#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Qual o seu nome?");
    string name = GetString();
    
    printf("Ola, %s\n", name);
}
