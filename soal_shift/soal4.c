#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>



void *faktorial(void *ptr);

int main(){
pthread_t test[10];
int i=0,angka[100],j=0, err;
char c=' ';
while(c!='\n'){
scanf("%d%c",&angka[i++],&c);
}
while(j<i)
    {   //int x= angka[j];
	j++;
        err=pthread_create(&(test[j]),NULL,faktorial, &angka[j]);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
	else printf("tr");

    }
for(int k=1; k<i;k++) {pthread_join(test[i],NULL);}
}

void *faktorial(void *ptr){
      int *gege = ptr;
      int angka1, hasil;
     int gogo= *gege;
      while(gogo!=1)
      { if(gogo==0)
          { hasil=1;
            break;
          }
	for(angka1=1;angka1<=gogo;angka1++){
        hasil=hasil*angka1;
	}
      }
      printf("Hasil %d!= %d",gogo,hasil);
}


