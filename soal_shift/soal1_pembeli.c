#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void main()
{
//        key_t key = 1234;
  //      int *value;
	
      //  int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
   //     value = shmat(shmid, NULL, 0);
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
	int  jumlah[6]= {1,1,1,2,3,4};
	while(1){
	scanf("%s", pilih);
	if(strcmp(pilih,c)==0) exit(EXIT_FAILURE);
	if(strcmp(pilih,a)==0){
	for(i=0;i<6;i++)
	{
	printf("%s %d\n", list[i], jumlah[i]);
	}
	}
	if(strcmp(pilih,"beli")==0){
	scanf("%s %d", menu1, &kurang);
	for(i=0;i<6;i++){
	if(strcmp(menu1,list[i])==0){
	jumlah[i]-=kurang;
	printf("%s %d\n", list[i],jumlah[i]);
			}

	}
}
}
 //       printf("Program 1 : %d\n", *value);
//	*value = 30;
		
      //  sleep(5);

    //    printf("Program 1: %d\n", *value);
  //      shmdt(value);
//        shmctl(shmid, IPC_RMID, NULL);
}
