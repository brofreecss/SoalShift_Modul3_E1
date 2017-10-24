#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t test[100];

void *faktorial(void *ptr);

int main(){
int i=0,angka[100],j=1, err;
char c=' ';
while(c!='\n'){
scanf("%d%c",&angka[i++],&c);
}
while(j<=i)//looping membuat thread 2x
    {   int x= angka[j];
        err=pthread_create(&(test[j]),NULL,faktorial,(void*) x);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        j++;
    }
for(int k=1;k<=i;k++) { pthread_join(test[k],NULL);}
}

void *faktorial(void *ptr){
      int angka1=ptr, angka2=ptr;
      while(angka1!=1)
      { if(ptr==0)
          { angka1=1;
            break;
          }
        angka1*=angka2-1;
        angka2--;
      }
      printf("Hasil %d!= %d",ptr,angka1);
return NULL;
}


