#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t test[100];

void faktorial(void* arg){
}

int main(){
int i=0,angka[100],j=1;
char c=' ';
while(c!='\n'){
scanf("%d%c",&angka[i++],&c);
}
while(j<=i)//looping membuat thread 2x
    {
        err=pthread_create(&(test[i]),NULL,&faktorial,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        j++;
    }
for(int k=1;k<=i;k++)  pthread_join(test[i],NULL);
}

