#include "Derivated.h"
#include <stdio.h>
#include <malloc.h>

struct derivated
{
    void (**vTable)();
    int x, y;
};

//Funções da Estrutura
void sayDerivated(Derivated d) {
    printf("Olá, eu sou uma classe derivada e meus valores são: x=%i e y=%i\n", d->x, d->y);
}

//Implementação da Tabela Virtual
enum {sayFunction};
void (*derivated_vTable[])() = {sayDerivated};

//Funções que Serão Chamadas pelo Usuário
Derivated newDerivated(int x, int y) {
    Derivated d = (Derivated) malloc(sizeof(struct derivated));
    d->x = x;
    d->y = y;
    d->vTable = derivated_vTable;

    return d;
}