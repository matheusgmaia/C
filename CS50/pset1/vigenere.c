#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// print array get strlen tolower

int h=0;
int main(int argc, string argv[])// argc é o numero de coisas quando roda o programa, argv ta amazenando cada uma
{
    string key = argv[1];
    for (int j = 0, m = strlen(key); j<m; j++)
    {
    if (argc != 2 || !isalpha (key[j]))// caso ele o input invalido erro
    {
    printf("Usage: ./cesar1 (key)\n");
    return 0;
    }
    }
    
    string p = GetString();
    for (int j = 0, n = strlen(p); j < n; j++)
    {
    if (p[j] != 32)
    {
    int r = tolower(p[j]);
    int l=(h % strlen(key));// modulo do resto da divisao para que a key possa ser menor que o texto porem sem dar problema
    int k = key[l]-'a';// para que a key seja um adicional do lugar da letra
    int s =((((r - 'a')+k)%26)+'a');// para dar a volta
    printf("%c", s);
    h++;// o h, que muda o foco na key nao pode mudar quando o else for acionado
    }
    
    else 
    printf(" ");
    }
    
    printf ("\n");
}
