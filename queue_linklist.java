class queue_linklist {
  
     class Node {
         int data;
         Node next;
         
         
  
         Node(int data) {
            this.data=data;
        }
    }
    Node newnode(int key) {
         Node temp=new Node(key); 
         return temp;
     }
    Node front,rear;
    
    void en_queue(int item) {
         if(front==null) {
            front= newnode(item);
             rear=front;
         }
         else {
          rear.next=newnode(item);
          rear = rear.next;}
           
     }
     void de_queue() {
         if(front==null)
             System.out.print("queue is empty ");

         else
            front=front.next;
      }
       void print() {
          Node temp=front;
           while(temp!=null) {
               System.out.print(temp.data+"  ");
                temp=temp.next;
           }
           System.out.println();
      }
     
     public static void main(String args[]) {
          queue_linklist obj=new queue_linklist();  
          obj.en_queue(3);

          obj.en_queue(1);
          obj.en_queue(5);
          obj.print();
           obj.de_queue();
          obj.print();
         

   }
}    
