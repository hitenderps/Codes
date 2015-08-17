#include <stdio.h>
#include <sys/time.h>
void Insertion_Sort(int arr[],int size) {
    int i,j,temp;

    for(i=1;i<=size;i++) {
    temp=arr[i];
    j=i-1;

        while(j>=0 && temp<arr[j]) {
            arr[j+1]=arr[j];
            j--;
         }   
    arr[j+1]=temp;
     }
}
    
main()  {

   struct timeval t1,t2;
   int i,n;
   double r;
   long unsigned int r1,r2
;
   printf("enter the no.of element\n");
   scanf("%d",&n);
   int arr[n];
                                                                                   gettimeofday(&t1,NULL);
   for(i=0;i<n;i++)
   arr[i]=i;
  // gettimeofday(&t1,NULL);
   Insertion_Sort(arr,n);
   gettimeofday(&t2,NULL);
   
   r1=((t2.tv_sec*10000000L+t2.tv_usec)-(t1.tv_sec*1000000L+t1.tv_usec));
   printf("%-10lu\n",r1);


   gettimeofday(&t1,NULL);
   for(i=n-1;i>=0;i--)
   arr[i]=i;
//    gettimeofday(&t1,NULL);
    Insertion_Sort(arr,n);
    gettimeofday(&t2,NULL);
   
   r2=((t2.tv_sec*10000000L+t2.tv_usec)-(t1.tv_sec*1000000L+t1.tv_usec));
   printf("%-10lu\n",r2);
   printf("%-4.3f\n",r1/(double)r2); 
   }
