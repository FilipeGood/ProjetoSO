#include "ficheiros.h"


int le_ficheiro(Config  config){
	ListaAut lista;
	ListaAut aux;
	FILE *f;
	char str[100];
	ListaAut c;
	lista =  (ListaAut) malloc(sizeof(ListaAut_node));
	

	//lista.comp=NULL;
	lista->next=NULL;
	/*c->comp=NULL;
	c->next=NULL;*/


	f= fopen("config.txt","r");
	if(!f){
		printf("Erro na leitura do ficheiro 'config.txt'!!!\n");
		return -1 ; /*retorna -1 em caso de erro*/
	}
	if(fgets(str,100,f)!=NULL){
			strtok(str, "=");
			
			config->porto= atoi(strtok(NULL,"\n"));

					}
	
	if(fgets(str,100,f)!=NULL){
		strtok(str,"=");
		strcpy(config->scheduling,strtok(NULL,"\n"));

	}
	if(fgets(str,100,f)!=NULL){
		strtok(str,"=");
		config->nthreads= atoi(strtok(NULL,"\n"));
		

	}
	if(fgets(str,100,f)!=NULL){
		strtok(str,"=");
	
	
		int i=0;
		do{
			i++;
			c= (ListaAut) malloc(sizeof(ListaAut_node));
			strcpy(c->comp,strtok(NULL,";"));
			aux = lista;
			while(aux->next!=NULL){
				aux=aux->next;
			}
			c->next= aux->next;
			aux->next=c;
			c->next=NULL;

			//c->comp=NULL;
		}		
		while(i<5);
		config->listaAll = lista;

		
	}

	
	printf("Porto = %d\n",config->porto);
	printf("scheduling= %s\n", config->scheduling);
	printf("Numero =%d\n",config->nthreads );
	printf("Allowed=");
	aux = config->listaAll;
	while(aux->next!=NULL){
		printf("%s;",aux->comp );
		aux = aux->next;
	}
	printf("\n");
	
	return 0;


}