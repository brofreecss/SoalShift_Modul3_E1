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
	int flag=1;

	int jumlah,temp;
	while(flag){
		printf("Masukkan berapa ranjau yang ingin diletakkan\n");
		scanf("%d",&jumlah);
		if(jumlah>0 && jumlah<=4)flag=0;
		else printf("Jumlah invalid\n");
	}
	int j,input[4];
	flag=0;

	for(j=0;j<jumlah;j++){
		scanf("%d",&input[j]);
		if(input[j]<=0 || input[j]>16)flag=1;

		if(flag && j==jumlah-1){
			printf("Angka invalid! pilih ulang\n");
			flag=0;
			j=0;
		}
	}

	for(j=0;j<jumlah;++j){
		lubang_pemain[i%2][input[j]]=1;
	}
}

void* game(void* arg){
	//tebak dulu, baru masukin ranjau
	long int i = (long int)arg;
	int angka[4],k=0,berhasil=0,jumlah,temp;
	printf("Tebak 4 angka (1-16):\n");
	int flag=0;
	for(k=0;k<4;++k) {
		scanf("%d",&angka[k]);
		if(angka[k]>0 && angka[k]<=16)continue;
		else{
			flag=1;
		}

		if(flag && k==3){
			printf("Angka invalid, pilih ulang\n");
			k=0;
			flag=0;
		}
	}
	//bisa di assert mungkin?


	berhasil=0;		
	for(k=0;k<4;++k){
		(lubang_pemain[(i+1)%2][angka[k]]!=0) ? skor_pemain[i%2]++,berhasil++ : skor_pemain[(i+1)%2]++;
	}

	printf("Anda berhasil menebak %d dengan benar\n",berhasil);
	pasang(i);
	return NULL;
}

void* tampil(void* arg){
	char dump;
	printf("%s : %d\n",nama_pemain_satu,skor_pemain[0]);
	printf("%s : %d\n",nama_pemain_dua,skor_pemain[1]);
	printf("Press any key to continue...\n");
	return NULL;
}

int hitung(void){
	int j;
	int count=0;
	for(j=0;j<16;++j){
		if(lubang_pemain[0][j]!=0)count++;
	}
	for(j=0;j<16;++j){
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

			pthread_t pt;
			int err;

			int query;
			scanf("%d",&query);
			
			if(query==1){
				char dump;
				printf("%s : %d\n",nama_pemain_satu,skor_pemain[0]);
				printf("%s : %d\n",nama_pemain_dua,skor_pemain[1]);
				printf("Press any key to continue...\n");
				getchar();
				getchar();
			}
			else if(query==2){
				err = pthread_create(&pt,NULL,game,(void*)i);
				if(err){
					fprintf(stderr, "error bosqu %d\n", err);
					exit(EXIT_FAILURE);
				}
				pthread_join(pt,NULL);
				system("clear");
				fflush(stdin);
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