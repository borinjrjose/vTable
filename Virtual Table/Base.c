#include "Base.h"
#include <stdio.h>
#include <malloc.h>

struct base
{
    void (**vTable)();
    int x;
};

//Funções da Estrutura
void sayBase(Base b) {
    printf("Olá, eu sou uma classe base e meu valor é: x=%i\n", b->x);
}

//Implementação da Tabela Virtual
enum {sayFunction};
void (*base_vTable[])() = {sayBase};

//Funções que Serão Chamadas pelo Usuário
Base newBase(int x) {
    Base b = (Base) malloc(sizeof(struct base));
    b->x = x;
    b->vTable = base_vTable;

    return b;
}

void say(Base b) {
    b->vTable[sayFunction](b);
}