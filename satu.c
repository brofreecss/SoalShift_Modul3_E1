#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int status;

void* pindah(void* arg){
	status=0;
	system("cp baca.txt salin1.txt");
	status=1;
	return NULL;
}

void* pindah2(void* arg){
	while(status!=1);
	system("cp salin1.txt salin2.txt");
	return NULL;
}


int main(){
	int iret,iret2;
	pthread_t tid;
	pthread_t tid2;

	iret = pthread_create(&tid,NULL,pindah,NULL);
	iret2 = pthread_create(&tid2,NULL,pindah2,NULL);

	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);

	return 0;
}