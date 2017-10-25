#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
void main()
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
	int  jumlah[6]= {0,1,1,2,3,4};
	while(1){
	scanf("%s", pilih);
	if(strcmp(pilih,c)==0) exit(EXIT_FAILURE);
	if(strcmp(pilih,a)==0){
	for(i=0;i<6;i++)
	{
	if(jumlah[i]!=0){
	printf("%s %d\n", list[i], jumlah[i]);}

	}
	}
	if(strcmp(pilih,"tambah")==0){
	scanf("%s %d", menu1,&plus);
	for(i=0;i<6;i++){
	if(strcmp(menu1,list[i])==0){
	jumlah[i]+=plus;
	printf("%s %d\n", list[i],jumlah[i]);
			}

	}
}
}
       int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        stock = shmat(shmid, NULL, 0);

        *stock = 10;

        printf("Program 1 : %d\n", *stock);

        sleep(5);
        printf("Program 1: %d\n", *stock);
        shmdt(stock);
     	shmctl(shmid, IPC_RMID, NULL);
}
