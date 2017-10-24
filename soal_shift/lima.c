#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

char[1000] nama_file;

void* periksa(void* arg){
	char* needle = (char*) arg;

	char buffer[10000];
	strcpy(buffer,"cat ");
	strcat(buffer,nama_file);
	strcat(buffer," | grep -o ");
	strcat(buffer, needle);
	strcat(buffer, " | wc -l");

	printf("%s :" needle);
	system(buffer);
}