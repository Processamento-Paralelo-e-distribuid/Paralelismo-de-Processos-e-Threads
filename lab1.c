/* 
    Paralelismo por mieo de processos/threads na ordenaçao de um vetor de grandes dimensoes;
    Comparar o tempo de execuçao de ordenação de vetores com diferentes quantidades de processos/threads;
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

typedef struct thread_vet {
  long int* inicio;
  long int* fim;  
} thread_vet;


void* ordena(void* arg){
    int index = *(int*)arg;
    //printf("%ld\n", vet[(k+1)*i]);
    //printf("%ld\n", vet[(k)*i]);
}

int main(int argc, char* argv[]){
    int k, n, num_part;
    FILE* entrada;
    
    entrada = fopen(argv[1], "r+");
    if(entrada == NULL){
        printf("\n\tArquivo de entrada nao encontrado\n");
        return 0;
    }

    fscanf(entrada, "%d", &k);
    fscanf(entrada, "%d", &n);
    
    if(n%k==0){
        num_part = n/k;
    } else {
        num_part = n/k +1;
    }

    long int vet[n];
    thread_vet partition[num_part];
    pthread_t thread[num_part];

    for(int i=0; i<n; i++){
        fscanf(entrada, "%ld", &vet[i]);
        //partition[i].inicio = vet+((k+1)*i);
        //partition[i].fim = vet+((k)*i);
    }
    for(int i=0; i<k; i++){
        printf("%ld - ", vet[(n/k)*(i)]);
        printf("%ld\n", vet[(n/k)*(i+1)-1]);
        //pthread_create(&thread[i], NULL, &ordena, vet+((k+1)*i));
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%ld\n", vet[i]);
    }

    fclose(entrada);
    return 0;
}