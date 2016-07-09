#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cs50.h>

int main(void)

{
    srand(time(NULL));//definir o aleatorio
    int skittles = rand() % 1024;
    
    printf ("Eu sou uma maquina de doce e quero que tente advinhar quantos doces eu tenho!\n");
    int tentativa = GetInt();// pedir tentativa e guarda-la
    
    while (tentativa != skittles){// até acertar
    int tentativa = GetInt();
    if (tentativa == skittles)
    {
    printf("Parabens vc consguiu!\n");
    return 0;//quando acertar acabar programa
    }
    else if (tentativa < skittles)
    {
    printf ("Vc colocou pouco\n");
    }
   else 
   {
   printf ("Vc colocou mtu\n");
   }
   }
}
