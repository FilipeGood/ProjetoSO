
int shmid, *configstruct;

int create_shared_men(){
	
	int *shared_var;

	//Create shared memory
	if((shmid= shmget(IPC_PRIVATE,sizeof(Config*),IPC_CREAT|0766)<0){
		perror("While creating shared memory!!\n");
	}	
	//Attach shared memory
	configstruct= (Config*)shmat(shmid,NULL,0);

	
	
	shmdt(NULL); // desliga a região da memória partilhada
	shmctl(shmid,IPC_RMID_NULL); //destroi a zona de memória partilhada
}



