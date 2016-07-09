#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int height = 0;
	// faça isso mas repita while nao atendida
	do {
		printf("Height:");
		height = GetInt();
       
	   } 
	while (height < 1 || height > 23);
    
    //para ter um piramide de ponta de dois
    int variavel =2;
    
    while(height != 0){
    for (int i=0;(i<height-1);i++)
    {
    printf(" ");
    }
    
    for (int j=0;j<variavel;j++ )
    {
    printf("#");
    }
    variavel = (variavel+1);// aumenta a variavel, diminui a altura e pula a linha
    height = (height - 1);
    printf("\n");
    }
}
