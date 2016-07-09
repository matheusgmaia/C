#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Oi, quanto vc precisa?\n");
    float troco = GetFloat();
    troco = troco- 1;
    printf("%f", troco);
}
