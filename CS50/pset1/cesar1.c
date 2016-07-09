#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// print array get strlen is lower
int main(int argc, string argv[])// argc é o numero de coisas quando roda o programa, argv ta amazenando cada uma
{
    int key = atoi(argv[1]);// a chave é o segundo troço
    
    if (argc != 2 || key<1)// caso ele o input invalido erro
    {
    printf("Usage: ./cesar1 (key)\n");
    return 0;
    }
    
    string p = GetString();
    for (int i = 0, n = strlen(p); i < n; i++)// letra por letra ate o tamanho do codigo
    {
    
    int r = tolower(p[i]);
    int s =((((r - 'a')+key)%26)+'a');// para dar a volta 
    printf("%c", s);
    
    }
    printf("\n");
    return 0;
}
