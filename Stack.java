
public class Stack {
    final int max=1000;
    int[] stack=new int[max];
    int top=-1;

   public void push(int item){
      if(top==max-1)
          System.out.println("stack overflow");
      else {
      top=top+1;
      stack[top]=item;
      }
   }
     
    public void pop() {
         if(top==-1)
            System.out.println("stack is empty");
         else
         top=top-1;
      }
    
    public void print() {
       System.out.print("stack status  ");
       for(int i=0;i<=top;i++)
          System.out.print(stack[i]+" ");
       System.out.println();
    
       }
    public static void main(String argv[]) {
         Stack obj=new Stack();
         obj.pop();
         obj.print();
         obj.push(5);
         obj.push(4);
         obj.push(8);
         obj.print();
          obj.pop();
           obj.print();
   }
}


        
       
