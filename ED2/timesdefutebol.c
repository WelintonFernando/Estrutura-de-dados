#include <stdio.h>
#include <string.h>
#define TF 5

/*
1. Implemente e teste os algoritmos de ordenação QuickSort e HeapSort
para ordenar um vetor de registros que representa uma tabela de campeonato
de futebol. A estrutura é TimeFutebol, com os campos nome (string) e pontuação(int).
A ordenação deve feita pelo campo pontuação.
*/



typedef struct sTimeFutebol {
    char nome[60];
    int pontuacao;
} TimeFutebol;

void swap(TimeFutebol *a, TimeFutebol *b) {
    TimeFutebol temp = *a;
    *a = *b;
    *b = temp;
}

void heapsort(TimeFutebol times[], int n, int *count) {
   int i = n / 2, pai, filho;
   TimeFutebol t;
   int ajustado;  

   while (1) {
      if (i > 0) {
          i--;
          t = times[i];
      } else {
          n--;
          if (n <= 0) {
              return;
          }  
          t = times[n];
          times[n] = times[0];  
      }

      pai = i;
      filho = i * 2 + 1;  
      ajustado = 0;  

      while (filho < n && !ajustado) {  
          if ((filho + 1 < n) && (times[filho + 1].pontuacao < times[filho].pontuacao))
              filho++;  

          if (times[filho].pontuacao < t.pontuacao) {  
             times[pai] = times[filho];  
             pai = filho;  
             filho = pai * 2 + 1;  
          } else {
             ajustado = 1;  
          }
          (*count)++;
      }
      times[pai] = t;  
   }
}

void quicksort(TimeFutebol times[], int ini, int fim, int *count) {
    int i = ini, j = fim;
    int pivo = times[(ini + fim) / 2].pontuacao;

    while (i <= j) {
        while (times[i].pontuacao > pivo) {  
            i++;
            (*count)++;
        }
        while (times[j].pontuacao < pivo) {  
            j--;
            (*count)++;
        }
        if (i <= j) {
            swap(&times[i], &times[j]);
            i++;
            j--;
            (*count)++;
        }
        (*count)++;
    }

    if (ini < j) {
        quicksort(times, ini, j, count);
    }
    if (i < fim) {
        quicksort(times, i, fim, count);
    }
}


void apresentar(TimeFutebol times[]) {
    for (int i = 0; i < TF; i++) {
        printf("Time: %s, Pontuação: %d\n", times[i].nome, times[i].pontuacao);
    }
    printf("\n");
}

void ler_times(TimeFutebol times[]) {
    for (int i = 0; i < TF; i++) {
        printf("Digite o nome do time %d: ", i + 1);
        scanf(" %[^\n]", times[i].nome);
        printf("Digite a pontuação do time %d: ", i + 1);
        scanf("%d", &times[i].pontuacao);
    }
}

int main() {
    TimeFutebol times[TF];
    int count = 0;
    int opcao;

    do {
        count = 0;
        printf("\nMenu:\n"
               "1 - Inserir times\n"
               "2 - Ordenar por HeapSort\n"
               "3 - Ordenar por QuickSort\n"
               "4 - Apresentar\n"
               "0 - Sair\n"
               "Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ler_times(times);
            break;

            case 2:
                heapsort(times, TF, &count);
                printf("Ordenado! \n"
                   "Contagem: %d\n", count);
            break;

            case 3:
                quicksort(times, 0, TF - 1, &count);
                printf("Ordenado! \n"
                   "Contagem: %d\n", count);
            break;

            case 4:
                apresentar(times);
            break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("invalido!\n");
        }
    } while (opcao != 0);

    return 0;
}
