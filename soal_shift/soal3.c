#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int lohan;
int kepiting;
int exit_stat;

void* makan(void* arg){
	long int binatang = (long int) arg;
	exit_stat=0;
	while(1){
		if(binatang==1){		//lohan
			if(lohan <= 0 || lohan > 100 || kepiting <=0 || kepiting> 100)break;
			sleep(10);
			lohan-=15;
		}
		else if(binatang==2){	//kepiting
			if(lohan <= 0 || lohan > 100 || kepiting <=0 || kepiting> 100)break;
			sleep(20);
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
		system("clear");
		printf("lihat : digunakan untuk melihat status sekarang\n");
		printf("lohan : beri makan lohan (tambah 10)\n");
		printf("kepiting : beri makan kepiting (tambah 10)\n");
		printf("manakah pilihanmu, wahai Aidil yang ingin diperhatikan?\n");
		scanf("%s",temp);
		
		if(strcmp(temp,"lihat")==0){
			printf("\nlohan: %d\nkepiting: %d\n",lohan,kepiting);
			getchar();
			getchar();
		}
		else{
			//scanf("%d",&jumlah);
			if(strcmp(temp,"lohan")==0){
				lohan+=10;
			}
			else if(strcmp(temp,"kepiting")==0){
				kepiting+=10;
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
	stat = pthread_create(&tid_lohan,NULL,makan,(void*)1);

	if(stat){
		fprintf(stderr,"error bosqu %d\n",stat);
		exit(EXIT_FAILURE);
	}

	stat = pthread_create(&tid_kepiting,NULL,makan,(void*)2);
	
	if(stat){
		fprintf(stderr,"error bosqu %d\n",stat);
		exit(EXIT_FAILURE);
	}

	stat = pthread_create(&tid_tambah,NULL,tambah,NULL);
	if(stat){
		fprintf(stderr,"error bosqu %d\n",stat);
		exit(EXIT_FAILURE);
	}

	//pthread_join(tid_lohan,NULL);
	//pthread_join(tid_kepiting,NULL);
	pthread_join(tid_tambah,NULL);

	printf("udah ~~~\n");

	return 0;
}