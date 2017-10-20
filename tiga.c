/*

	Soal no 3
	Pemutar musik

	source:
	https://stackoverflow.com/questions/8943464/linux-shell-vlc-programming
	https://n0tablog.wordpress.com/2009/02/09/controlling-vlc-via-rc-remote-control-interface-using-a-unix-domain-socket-and-no-programming/


	Implementasi menggunakan socket bawaan VLC.

*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char temp[10];

	char nama_file[1000];


	system("cvlc -I rc --rc-host localhost:11337 -d");

	while(1){
		scanf("%s",temp);
		if(strcmp(temp,"exit")==0){
			system("echo quit | netcat localhost 11337 > /dev/null");
			break;
		}
		else if(strcmp(temp,"add")==0){
			scanf("%s",nama_file);
			char command[10000];
			strcpy(command,"echo add ");
			strcat(command,nama_file);
			strcat(command," | netcat localhost 11337 > /dev/null");
			system(command);

		}
		else if(strcmp(temp,"help")==0){
			system("echo help | netcat localhost 11337");
		}
		else if(strcmp(temp,"play")==0){
			system("echo play | netcat localhost 11337 > /dev/null");
		}
		else if(strcmp(temp,"pause")==0){
			int seconds;
			scanf("%d",&seconds);
			sleep(seconds);
			system("echo pause | netcat localhost 11337 > /dev/null");
		}
		else if(strcmp(temp,"continue")==0){
			int seconds;
			scanf("%d",&seconds);
			sleep(seconds);
			system("echo play | netcat localhost 11337 > /dev/null");
		}
		else if(strcmp(temp,"stop")==0){
			int seconds;
			scanf("%d",&seconds);
			sleep(seconds);
			system("echo stop | netcat localhost 11337 > /dev/null");
		}
		else if(strcmp(temp,"playlist")==0){
			system("echo playlist 2 | netcat localhost 11337");
		}
	}
}