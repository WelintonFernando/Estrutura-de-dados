#include <stdio.h>
#define TF 10
typedef struct sPilha
{
    int topo;
    int pilha[TF];
}PILHA;

PILHA inicia_Pilha(){
    PILHA p;
    p.topo = -1;
    return p;
}
// não seria necessário usar ponteiro, mas estou usando para ficar mais fácil de
// escrever as outras funções, caso contrário teria que ficar toda hora escrevendo (*p)
int vazia(PILHA *p){ 
    if(p->topo == -1){
        return 1;
    }
    return 0;
}

// usei int aqui para que o return fique mais bonito. adicionalmente, não precisa retornar o valor
// inserido, nem deveria. fiz isso para poder ficar mais visual no print, mas poderia ser um return
// de 0 para falha e 1 para sucesso. nesse caso, -1 para falha e o valor inserido para sucesso.
int inserir(PILHA *p, int valor){
    if (p->topo == TF -1){
        printf("Pilha cheia\n");
        return -1;
    }
    p->topo++;
    p->pilha[p->topo] = valor;
    return valor;    
}

// retorna o valor removido decrementando o topo.

int remover(PILHA *p){
    if(vazia(p)){
        printf("Pilha vazia\n");
        return -1;
    }
    int valor = p->pilha[p->topo]; 
    p->topo--;
    return valor;
}

// aqui não precisa ser ponteiro, você só vai apresentar o conteúdo.
void apresentar(PILHA p){
    while (p.topo > -1)
    {
        printf("|%d|\n", p.pilha[p.topo]);
        p.topo--;
    }
}

int main(){

    PILHA p;
    p = inicia_Pilha();

    inserir(&p, 1);
    inserir(&p, 2);
    inserir(&p, 4);
    inserir(&p, 9);
    inserir(&p, 3);
    printf("---------- PILHA ----------\n");
    apresentar(p);
    printf("---------- PILHA ----------\n");
    printf("|%d| REMOVIDO\n", remover(&p));
    printf("|%d| REMOVIDO\n", remover(&p));
    printf("|%d| REMOVIDO\n", remover(&p));
    printf("---------- PILHA ----------\n");
    apresentar(p);
    printf("---------- PILHA ----------\n");
    printf("|%d| INSERIDO\n",inserir(&p, 3));
    printf("|%d| INSERIDO\n",inserir(&p, 2));
    printf("|%d| INSERIDO\n",inserir(&p, 1));
    printf("---------- PILHA ----------\n");
    apresentar(p);
    printf("---------- PILHA ----------\n");

    return 0;
}
