#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int lohan;
int kepiting;

void* makan(void* arg){
	int* binatang = (int*) arg;
	while( (lohan>=0 && lohan<=100) || (kepiting>=0 && kepiting<=100)){
		if(*binatang == 1){		//lohan
			sleep(10);
			lohan-=15;
		}
		else{					//kepiting
			sleep(20);
			kepiting-=10;
		}
	}
	return NULL;
}