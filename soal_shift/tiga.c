#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int lohan;
int kepiting;
int exit_stat;

void* makan(void* arg){
	char* binatang = (char*) arg;
	exit_stat=0;
	while(1){
		if(strcmp(binatang,"lohan")==0){		//lohan
			if(lohan <= 0 || lohan > 100 || kepiting <=0 || kepiting> 100)break;
			sleep(5);
			lohan-=15;
		}
		else {					//kepiting
			if(lohan <= 0 || lohan > 100 || kepiting <=0 || kepiting> 100)break;
			sleep(5);
			kepiting-=10;
		}
	}
	exit_stat=1;
	return NULL;
}

void* tambah(void* arg){
	char temp[1000];
	int jumlah;
	while(1){
		scanf("%s",temp);
		if(strcmp(temp,"c")==0){
			printf("%d %d\n",lohan,kepiting);
		}
		else{
			scanf("%d",&jumlah);
			if(strcmp(temp,"lohan")==0){
				lohan+=jumlah;
			}
			else if(strcmp(temp,"kepiting")==0){
				kepiting+=jumlah;
			}
		}
		if(lohan <= 0 || lohan > 100 || kepiting <=0 || kepiting> 100)break;
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t tid_lohan,tid_kepiting,tid_tambah;
	int stat;
	lohan = kepiting = 100;
	stat = pthread_create(&tid_lohan,NULL,makan,(void*)"lohan");

	if(stat){
		fprintf(stderr,"error bosqu %d\n",stat);
		exit(EXIT_FAILURE);
	}

	stat = pthread_create(&tid_kepiting,NULL,makan,(void*)"kepiting");
	
	if(stat){
		fprintf(stderr,"error bosqu %d\n",stat);
		exit(EXIT_FAILURE);
	}

	stat = pthread_create(&tid_tambah,NULL,tambah,NULL);
	if(stat){
		fprintf(stderr,"error bosqu %d\n",stat);
		exit(EXIT_FAILURE);
	}

	pthread_join(tid_lohan,NULL);
	pthread_join(tid_kepiting,NULL);
	pthread_join(tid_tambah,NULL);

	printf("udah ~~~\n");

	return 0;
}