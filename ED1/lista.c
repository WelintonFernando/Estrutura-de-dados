#include <stdio.h>
#include <stdlib.h>
#define TF 10 // Tamanho da lista

/*
Esse arquivo contém a implementação de uma lista estática.

A lista é uma estrutura de dados que armazena elementos de forma sequencial,
nela, você pode inserir, remover e buscar elementos de qualquer posição.
*/


typedef struct sLista{
    int lista[TF];
    int tamanho;
}LISTA;

// vamos iterar pela lista segundo a sua quantidade de elementos
// fazemos isso para apenas o necessário. Logo, iniciamos o tamanho em 0.
void inicialista(LISTA *l){
    l->tamanho = 0;
}

// aqui verificamos se a lista está vazia, ou seja "tamanho" é igual a 0
// basicamente essa função retorna verdadeiro ou falso.
int lista_vazia(LISTA *l){
    if(l->tamanho == 0){
        return 1;
    }
    return 0;
}

// na lista, temos essas funções de inserção, remoção e busca.
// a seguir, temos a função de inserção no início da lista.
// se temos a lista [1, 2, 3, 4] e inserimos o valor 0, a lista ficará [0, 1, 2, 3, 4]
// para isso, "arrastamos" todos os elementos para a direita e inserimos o novo valor no início.
void insere_inicio(LISTA *l, int valor){
    if(l->tamanho < TF){
        for(int i = l->tamanho; i > 0; i--){
            l->lista[i] = l->lista[i-1];
        }
        l->lista[0] = valor;
        l->tamanho++;
    }else{
        printf("Lista cheia\n");
    }
    
}

// mesma lógica, porém inserindo no final.
void insere_fim(LISTA *l, int valor){
    if(l->tamanho < TF){
        l->lista[l->tamanho] = valor;
        l->tamanho++;
    }else{
        printf("Lista cheia\n");
    }
}

// uma lista não tem limitação de onde podemos inserir um elemento como
// um deque ou pilha, dessa forma, podemos inserir em qualquer posição.
// aqui, contém a mesma lógica da inserção no início, porém com a posição desejada.
void inserir_posicao(LISTA *l, int valor, int posicao){
    if(l->tamanho < TF){
        if(posicao >= 0 && posicao <= l->tamanho){
            for(int i = l->tamanho; i > posicao; i--){
                l->lista[i] = l->lista[i-1];
            }
            l->lista[posicao] = valor;
            l->tamanho++;
        }else{
            printf("Posição inválida\n");
        }
    }else{
        printf("Lista cheia\n");
    }
}


// as próximas funções são de remoção, nesse caso, removendo do inicio.
void remover_inicio(LISTA *l){
    if(!lista_vazia(l)){
        for(int i = 0; i < l->tamanho; i++){
            l->lista[i] = l->lista[i+1];
        }
        l->tamanho--;
    }else{
        printf("Lista vazia\n");
    }
}

// removendo do fim.
void remover_fim(LISTA *l){
    if(!lista_vazia(l)){
        l->tamanho--;
    }else{
        printf("Lista vazia\n");
    }
}

void remover_posicao(LISTA *l, int posicao){
    if(!lista_vazia(l)){
        if(posicao >= 0 && posicao < l->tamanho){
            for(int i = posicao; i < l->tamanho; i++){
                l->lista[i] = l->lista[i+1];
            }
            l->tamanho--;
        }else{
            printf("Posição inválida\n");
        }
    }else{
        printf("Lista vazia\n");
    }
}

// agora faremos a apresentação da lista.
void apresentar_lista(LISTA *l){
    if(!lista_vazia(l)){
        for(int i = 0; i < l->tamanho; i++){
            printf("|%d ", l->lista[i]);
        }
        printf("|\n");
    }else{
        printf("Lista vazia\n");
    }
}


int main(){
    LISTA l;

    // como na função de inicialização passamos como parâmetro um ponteiro
    // para um tipo LISTA "l", passamos o endereço de memória da nossa lista.
    // assim para todas as outras funções que usam "LISTA *l" como parâmetro.
    inicialista(&l); 

    insere_inicio(&l, 1);
    insere_inicio(&l, 2);
    insere_inicio(&l, 3);
    apresentar_lista(&l);
    // a lista está [3, 2, 1]

    remover_inicio(&l);
    apresentar_lista(&l);
    // a lista está [2, 1]

    insere_fim(&l, 0);
    apresentar_lista(&l);
    // a lista está [2, 1, 0]

    remover_posicao(&l, 1);
    apresentar_lista(&l);
    // a lista está [2, 0]

    inserir_posicao(&l, 1, 0);
    apresentar_lista(&l);
    // a lista está [1, 2, 0]
}
