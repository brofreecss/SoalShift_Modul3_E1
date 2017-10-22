#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int lo,hi;
int status;

pthread_t test;

void* print(void* arg){
//	while(status!=1);
//	status=0;
	int i,j,flag;
	for(i=lo;i<hi;++i){
		flag=0;
		for(j=2;j<lo;++j){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(flag)continue;
		else printf("%d\n",i);
	}
//	status=1;
	return NULL;
}

int main(int argc, char const *argv[])
{
	int atas,t,bawah=2,count=1;
	scanf("%d %d",&atas,&t);
	while(bawah < atas){
		lo = bawah;
		hi = bawah + (atas/t);

		printf("Thread %d : \n",count++);
		int iret;
		iret = 	pthread_create(&test,NULL,print,NULL);
		if(iret){
			fprintf(stderr,"Thread creation failure, return code %d\n",iret);
			exit(EXIT_FAILURE);
		}

		pthread_join(test,NULL);

		bawah+=(atas/t);

	}
	return 0;
}