#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int lubang_pemain[2][20];

char nama_pemain_satu[1000];
char nama_pemain_dua[1000];

int skor_pemain[2];

pthread_t tid[3];

void pasang(int i){
	int jumlah,temp;
	printf("Masukkan berapa ranjau yang ingin diletakkan\n");
	scanf("%d",&jumlah);
	while(jumlah--){
		scanf("%d",&temp);
		lubang_pemain[i%2][temp]=1;
	}
}

void* game(void* arg){
	//tebak dulu, baru masukin ranjau
	long int i = (long int)arg;
	int angka[4],k,berhasil=0,jumlah,temp;
	printf("Tebak 4 angka (1-16):\n");
	for(k=0;k<4;++k) scanf("%d",&angka[k]);
	//bisa di assert mungkin?

	for(k=0;k<4;++k)
		(lubang_pemain[(i+1)%2][angka[k]]!=0) ? skor_pemain[i%2]++,berhasil++ : skor_pemain[(i+1)%2]++;

	printf("Anda berhasil menebak %d dengan benar\n",berhasil);
	pasang(i);
	return NULL;
}

int hitung(void){
	int j;
	int count=0;
	for(j=0;j<16;++j){
		if(lubang_pemain[0][j]!=0)count++;
		if(lubang_pemain[1][j]!=0)count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	//sebelum mulai game, ada inisialisasi posisi dulu
	system("clear");
	printf("Input nama pemain pertama : ");
	scanf("%s",nama_pemain_satu);
	pasang(0);
	system("clear");


	printf("Input nama pemain kedua : ");
	scanf("%s",nama_pemain_dua);
	pasang(1);
	system("clear");

	skor_pemain[0] = skor_pemain[1] = 0;

	long int i,j;
	for(i=0;;++i){
		if(skor_pemain[0] >= 10 || skor_pemain[1] >= 10)break;

		if(hitung()==32)break;

		while(1){
			printf("Sekarang giliran pemain ke - %d.\n",(int)(i%2)+1);
			printf("1. cek skor\n");
			printf("2. main\n");
			printf("Mau ngapain? (1/2): \n");

			int query;
			scanf("%d",&query);
			if(query==1){
				printf("%s : %d\n",nama_pemain_satu,skor_pemain[0]);
				printf("%s : %d\n",nama_pemain_dua,skor_pemain[1]);
				printf("Press any key to continue...\n");
				fflush(stdout);
				getchar();
			}
			else if(query==2){
				pthread_t pt;
				int err = pthread_create(&pt,NULL,game,(void*)i);
				if(err){
					fprintf(stderr, "error bosqu %d\n", err);
					exit(EXIT_FAILURE);
				}
				pthread_join(pt,NULL);
				system("clear");
				break;
			}
			system("clear");
		}	
	}

	//tambahin kl draw
	char winner[1000];
	strcpy(winner,(skor_pemain[0]>skor_pemain[1])?nama_pemain_satu:nama_pemain_dua);
	printf("Game berakhir dimenangkan %s dengan skor %d\n",winner,(skor_pemain[0]>skor_pemain[1])?skor_pemain[0]:skor_pemain[1]);

	return 0;
}

/*

int err = pthread_create(&tid[i^0],NULL,bermain,NULL);
		if(err){
			fprintf(stderr, "gagal rek %d\n",err);
			exit(EXIT_SUCCESS);
		}
		pthread_join(tid[i^0],NULL);

*/