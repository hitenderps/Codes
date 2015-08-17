#include <stdio.h>
#include<sys/time.h>

void swap(int *x,int *y) {

       int temp;
        temp=*x;
         *x=*y;
          *y=temp;
       }

int  min_term(int arr[],int start,int size) {
   int n=size;
    int min,loc,i;
    min=arr[start];
   loc=start;
    for(i=start;i<n;i++) {
        if(arr[i]<min)
           loc=i;
           }return loc;
    }


void selection_sort(int arr[],int size) {
     int n=size;
     int i,l;
     for(i=0;i<n;i++) {

     l= min_term(arr,i,n);
      swap(&arr[l],&arr[i]);
     }
}
int change(char* x) {
   int y=0;
  while(*x>='0' && *x<='9') {
   y=y*10+(*x-'0');
      x++;
   }
      return y; }     

   int main(int argc,char* argv[]) {
       struct timeval t1,t2;
       int n,i,j;
       double r=0;
       long unsigned int r1; 
       printf("Size  \tTime\t\t\  \tRatio\n");       
 for(i=1;i<argc;i++) {
            n=change(argv[i]);
            int arr[n];

          for(j=0;j<n;j++) {
              arr[j]=rand();
               }
              

              gettimeofday(&t1,NULL);
              selection_sort(arr,n);
              gettimeofday(&t2,NULL);
              
              
            r=(i==1)?0:((t2.tv_sec*1000000L+t2.tv_usec)-t1.tv_sec*1000000L+t1.tv_usec)/(double)r1;

           


              
printf("%6d\t%-10lu%-4.3f\n",n,(t2.tv_sec*1000000L+t2.tv_usec)-(t1.tv_sec*1000000L+t1.tv_usec),r);
    r1=(t2.tv_sec*1000000L+t2.tv_usec)-(t1.tv_sec*1000000L+t1.tv_usec);       
  }

/*scanf("%d",&n);
    int arr[n],i,j;

   // printf("enter the  number");

    for(i=0;i<n;i++) {
   
       arr[i]=i;
          }
         gettimeofday(&t1,NULL);
         selection_sort(arr,n);
         gettimeofday(&t2,NULL);
        // for(i=0;i<n;i++)
        // printf("%d\n",arr[i]);
         printf("\n%lu",t2.tv_usec-t1.tv_usec);*/
        }

