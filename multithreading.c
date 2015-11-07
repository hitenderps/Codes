#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define Buffer_Size 3

pthread_mutex_t m;
pthread_cond_t consumed=PTHREAD_COND_INITIALIZER;
pthread_cond_t produced=PTHREAD_COND_INITIALIZER;
int buffer[Buffer_Size];
int n=0;
int in,out;

void *producer() {
      int i,x;
      for(i=0;i<6;i++) {
           pthread_mutex_lock(&m);
           if(n==Buffer_Size)
               pthread_cond_wait(&consumed,&m);
           x=rand()%100;
           buffer[in]=x;
           in=(in+1)%Buffer_Size;
	   n++;
           printf("PRODUCER= %d\n",in);
          pthread_mutex_unlock(&m);
          pthread_cond_signal(&produced);
      }
}
void *consumer1() {
     int i,x;
     for(i=0;i<3;i++) {
         pthread_mutex_lock(&m);
     if(n==0) 
         pthread_cond_wait(&produced,&m);
     x=buffer[out];
     out=(out+1)%Buffer_Size;
     n--;
     printf("CONSUMER1= %d\n",out);
     pthread_mutex_unlock(&m);
     pthread_cond_signal(&consumed);
     }
}

void *consumer2() {
     int i,x;
     for(i=0;i<3;i++) {
         pthread_mutex_lock(&m);
     if(n==0) 
         pthread_cond_wait(&produced,&m);
     x=buffer[out];
     out=(out+1)%Buffer_Size;
     n--;
     printf("CONSUMER2= %d\n",out);
     pthread_mutex_unlock(&m);
     pthread_cond_signal(&consumed);
     }
}
int main() {
    pthread_t pid,cid;
   
   pthread_create(&pid,NULL,producer,NULL);
   pthread_create(&cid,NULL,consumer1,NULL);
   pthread_create(&cid,NULL,consumer2,NULL);
  pthread_join(pid,NULL);
  pthread_join(cid,NULL);
}
