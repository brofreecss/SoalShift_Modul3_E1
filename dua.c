#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int lo,hi;

void* print(void* arg){
	while(status!=1);
	status=0;
	int i,j,flag;
	for(i=lo,i<=hi;++i){
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
	status=1;
	return NULL;
}

