#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
void main()
{
        key_t key = 1234;
	char menu1,pilih;
	char a[10];
	char b[10];
	strcpy(a,"lihat");
	strcpy(b,"tambah");
        int *stock, i, plus;
	const char *list[6];
	list[0]= "MP4A1";
	list[1]= "PM2-V1";
	list[2]= "SPR-3";
	list[3]= "SS2-V5";
	list[4]= "SPG1-V3";
	list[5]= "MINE";
	int  jumlah[6]= {0,1,1,2,3,4};
	fgets(pilih, sizeof(pilih),stdin);
	if(strcmp(pilih,a)==0){
	for(i=0;i<6;i++)
	{
	if(jumlah[i]!=0){
	printf("%s %d\n", list [i], jumlah[i]);}
	}
	}
//	if(strcmp(pilih,"tambah")==0){
//	scanf("%s %d", menu1,&plus);
//	for(i=0;i<6;i++){
//	if(menu1=='list[i]'){
//	list[i]+=plus;}
//	}
//	}
       // int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
       // stock = shmat(shmid, NULL, 0);

       // *stock = 10;

       // printf("Program 1 : %d\n", *stock);

       // sleep(5);

       // printf("Program 1: %d\n", *stock);
       // shmdt(stock);
        //shmctl(shmid, IPC_RMID, NULL);
}
