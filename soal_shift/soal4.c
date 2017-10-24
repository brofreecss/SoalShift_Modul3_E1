#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *faktorial(void *ptr);


int main(int argc, char const *argv[]){
  pthread_t test[10];
  int i=0,j=-1, err;
  long int angka[100];
  // char c=' ';
  
  for(i=1;i<argc;++i){
    angka[i-1] = strtol(argv[i],NULL,10);
  }
  // for(i=0;i<argc-1;++i)printf("%ld ",angka[i]);
  //   printf("\n");

  // while(c!='\n'){
  //   scanf("%d%c",&angka[i++],&c);
  // }

  for(j=0;j<argc-1;++j) {   //int x= angka[j];
    err=pthread_create(&(test[j]),NULL,faktorial, (void*)angka[j]);//membuat thread
    if(err!=0)//cek error
    {
      printf("\n can't create thread : [%s]",strerror(err));
    }
    //else printf("tr");

//    pthread_join(test[j],NULL);
  }
  for(j=0; j<argc-1;++j) {pthread_join(test[j],NULL);}
}

void *faktorial(void *ptr){
  long int angka1, hasil=1;
  long int gogo= (long int)ptr;
//  printf("%ld\n",lim);
//  while(gogo!=1){ 
    if(gogo==0)
    { 
      hasil=1;
    }
    else {
      for(angka1=1;angka1<=gogo;angka1++){
        hasil=hasil*angka1;
//      printf("%ld\n",hasil);
      }
    }
//  }
  printf("Hasil %ld!= %ld\n",gogo,hasil);

  return NULL;
}


