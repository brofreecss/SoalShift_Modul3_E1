#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int lohan;
int kepiting;
int exit;

void* makan(void* arg){
	int* binatang = (int*) arg;
	exit=0;
	while((lohan>=0 && lohan<=100) || (kepiting>=0 && kepiting<=100)){
		if(*binatang == 1){		//lohan
			sleep(10);
			lohan-=15;
		}
		else{					//kepiting
			sleep(20);
			kepiting-=10;
		}
	}
	exit=1;
	return NULL;
}

void* tambah(void* arg){
	char temp[1000];
	int jumlah;
	while((lohan>=0 && lohan<=100) || (kepiting>=0 && kepiting<=100)){
		if(exit==1)break;
		scanf("%s",temp);
		scanf("%d",&jumlah);
		if(strcmp(temp,"lohan")==0){
			lohan+=jumlah;
		}
		else{
			kepiting+=jumlah;
		}
	}
	return NULL;
}

