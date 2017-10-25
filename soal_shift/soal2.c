#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int lubang_pemain_satu[20];
int lubang_pemain_dua[20];

char nama_pemain_satu[1000];
char nama_pemain_dua[1000];

int skor_pemain_satu;
int skor_pemain_dua;

pthread_t tid[3];

void* bermain(void* arg){
	pthread_t id = pthread_self();
	if(pthread_equal(id,tid[0])){		//pemain satu

	}
	else if(pthread_equal(id,tid[1])){	//pemain dua

	}
}

int main(int argc, char const *argv[])
{
	system("clear");
	printf("Input nama pemain pertama : ");
	scanf("%s",nama_pemain_satu);
	printf("Input nama pemain kedua : ");
	scanf("%s",nama_pemain_dua);

	system("clear");

	skor_pemain_satu = skor_pemain_dua = 0;

	//sebelum mulai game, ada inisialisasi posisi dulu


	unsigned int i,j;
	for(i=0;;++i){
		if(skor_pemain_satu >= 10 || skor_pemain_dua >= 10)break;

		int count=0;
		for(j=0;j<16;++j){
			if(lubang_pemain_satu[j]!=0)count++;
			if(lubang_pemain_dua[j]!=0)count++;
		}
		if(count==32)break;

		int err = pthread_create(&tid[i^0],NULL,bermain,NULL);
		if(err){
			fprintf(stderr, "gagal rek %d\n",err);
			exit(EXIT_SUCCESS);
		}
		pthread_join(tid[i^0],NULL);
	}


	return 0;
}