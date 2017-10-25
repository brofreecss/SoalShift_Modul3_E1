#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	key_t key = 1234;
	char pilih[10],menu1[10];
	char a[10];
	char b[10];
	char c[10];
	strcpy(a,"lihat");
	strcpy(b,"tambah");
	strcpy(c,"exit");
    
    int *stock, i, plus;
	const char *list[6];

	list[0]= "MP4A1";
	list[1]= "PM2-V1";
	list[2]= "SPR-3";
	list[3]= "SS2-V5";
	list[4]= "SPG1-V3";
	list[5]= "MINE";

	int shmid = shmget(key,sizeof(int)*6,IPC_CREAT | 0666);
	int *jumlah;
	jumlah = shmat(shmid,NULL,0);

	//init value
	for(i=0;i<6;++i)
		jumlah[i]=1;

	while(1){
		system("clear");
		printf("lihat / tambah / exit\n");
		printf("manakah pilihanmu, O Hawari?\n");
		scanf("%s", pilih);
		if(strcmp(pilih,c)==0) break;
		else if(strcmp(pilih,a)==0){
			system("clear");
			for(i=0;i<6;i++)
			{
				if(jumlah[i]!=0){
					printf("%s: %d\n", list[i], jumlah[i]);
				}
			}
			printf("\nPress any key to continue...\n");
			getchar();
		}
		else if(strcmp(pilih,"tambah")==0){
			scanf("%s %d", menu1,&plus);
			for(i=0;i<6;i++){
				if(strcmp(menu1,list[i])==0){
					jumlah[i]+=plus;
					printf("update jumlah : %s %d\n", list[i],jumlah[i]);
				}
			}
			printf("Press any key to continue...\n");
			getchar();
		}
		getchar();
	}

	shmdt(jumlah);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;

	// int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	// stock = shmat(shmid, NULL, 0);

	// *stock = 10;

	// printf("Program 1 : %d\n", *stock);

	// sleep(5);
	// printf("Program 1: %d\n", *stock);
	// shmdt(stock);
	// shmctl(shmid, IPC_RMID, NULL);
}
