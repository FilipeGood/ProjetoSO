
// PROJETO SO 2016/2017
// FILIPE GOOD && HENRIQUE BRANQUINHO
// Compile as: gcc store_solution.c -lpthread -D_REENTRANT -Wall -o store


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "ficheiros.h"



Config configstruct;
pthread_t * threads;
int * threadsid;

void cria_pool_threads();
void destroi_pool_threads();
void * worker();

int main(){
	le_ficheiro(configstruct);
	printf("(((((((  --  %d ----_",configstruct.nthreads);
	cria_pool_threads(configstruct.nthreads);

	destroi_pool_threads(configstruct.nthreads);

	return 0;
}



void cria_pool_threads(int nthreads)
{
	printf("\n----%d----\n",nthreads);
	int i;
    if ((threads = (pthread_t*)malloc(sizeof(pthread_t)*nthreads)) == NULL) perror("Allocating space for thread pool\n");
	if ((threadsid = (int*)malloc(sizeof(int)*nthreads)) == NULL) perror("Allocating space for thread pool id\n");
	for(i = 0; i < nthreads; i++){
		threadsid[i] = i;
		if(pthread_create(&threads[i],NULL,worker,&threadsid[i])) perror("Error creating thread\n");
	}

}

void destroi_pool_threads(int nthreads){
	printf("\n--!--%d--!--\n",nthreads);
	int i;
	for(i = 0; i < nthreads; i++){
		pthread_join(threads[i],NULL);
	}
	free(threads);
	free(threadsid);
}

void * worker(void* id_ptr){
	int id = *((int *)id_ptr);
	printf("OI %d\n",id);
}



