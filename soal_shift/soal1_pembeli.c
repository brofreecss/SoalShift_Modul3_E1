#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    key_t key = 1234;

	char pilih[10],menu1[10];
	char a[10];
	char b[10];
	char c[10];
	strcpy(a,"lihat");
	strcpy(b,"beli");
	strcpy(c,"exit");
    
    int *stock, i, kurang;
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
		printf("lihat / beli / exit\n");
		printf("manakah pilihanmu, pembeli?\n");
		scanf("%s", pilih);
		if(strcmp(pilih,c)==0) break;
		else if(strcmp(pilih,a)==0){
			for(i=0;i<6;i++)
			{
				printf("%s %d\n", list[i], jumlah[i]);
			}
			printf("\nPress any key to continue...\n");
			getchar();
		}

		else if(strcmp(pilih,b)==0){
			scanf("%s %d", menu1, &kurang);
			for(i=0;i<6;i++){
				if(strcmp(menu1,list[i])==0){
					jumlah[i]-=kurang;
					printf("Barang %s terbeli %d buah\n", list[i],jumlah[i]);
				}
			}
			printf("\nPress any key to continue...\n");
			getchar();
		}
		getchar();
	}
	shmdt(jumlah);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
 //       printf("Program 1 : %d\n", *value);
//	*value = 30;
		
      //  sleep(5);

    //    printf("Program 1: %d\n", *value);
  //      shmdt(value);
//        shmctl(shmid, IPC_RMID, NULL);
}
