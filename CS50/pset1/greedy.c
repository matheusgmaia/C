#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Oi. Quanto troco voce deve?\n");
    float troco = GetFloat();
    float parcial = 0;//parcial moedas, a cda while atendido ele aumenta 1
    
    while ( 0.25<=troco){
    (parcial++);
    troco = (troco - 0.25);
    }
    
    while ( 0.10<=troco){
    (parcial++);
    troco = (troco - 0.10);
    }
    
    while ( 0.05<=troco){
    (parcial++);
    troco = (troco - 0.05);
    }
    
    while ( 0.01<=troco){
    (parcial++);
    troco = (troco - 0.01);
    }
    //transformando um float num int
    int nmoedas = parcial;
    printf("Voce vai precisar dar %i moedas\n", nmoedas);
    
}
