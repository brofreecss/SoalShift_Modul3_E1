#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

char nama_file [1000];

void* periksa(void* arg){
	char* needle;
	needle = (char*) arg;

	char buffer[10000];
	strcpy(buffer,"cat ");
	strcat(buffer,nama_file);		//tambah nama file
	strcat(buffer," | grep -o ");
	strcat(buffer, needle);			//tambah string yang mau dicari
	strcat(buffer, " | wc -l");

	char buffer2[1000];
	strcpy(buffer2,"echo -n ");
	strcat(buffer2,needle);
	strcat(buffer2,"\" : \"");

	system(buffer2);
	system(buffer);
}

int main(int argc, char const *argv[])
{
	int i;

	// jangan lupa input nama file
	strcpy(nama_file,"Novel.txt");

	pthread_t tid[100];
	int tid_stat;
	for(i=0;i<argc-1;++i){
		tid_stat = pthread_create(&tid[i],NULL,periksa,(void*)argv[i+1]);
		if(tid_stat){ // jika gagal
			//kasi error
			fprintf(stderr,"gagal wtf %d\n",tid_stat);
			exit(EXIT_FAILURE);
		}
		pthread_join(tid[i],NULL);
	}
//	for(i=0;i<argc-1;++i) 
	return 0;
}