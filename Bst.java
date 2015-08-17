import java.util.*;

class Bst {
                
    class Node {
       int key;
      Node left;
      Node right;

      Node(int Key) {
         this.key=Key;
   }
}



    Node newnodes(Node root,int key) {

         
          Node newnode=new Node(key);
          newnode.left=newnode.right=null;
          return newnode;
    }

    
   Node addnode(Node root,int key) {
        if(root==null){
            root=newnodes(root,key);
            return root;
        }
        if(root.key>key)
            root.left=addnode(root.left,key);
        if(root.key<key)
            root.right=addnode(root.right,key);
        return root;
    }

    void inorder(Node root){
        if(root==null)
            return;
         inorder(root.left);
         System.out.print(root.key+"  ");
         inorder(root.right);
     }
  
     Node minimum(Node root) {
          Node temp;
          temp=root;
         while(temp.left==null)
             temp=temp.left;
        return temp;
     }

     
     Node delete(Node root,int item) {
         if(root==null)
             return root;
         if(root.key > item)
             root.left=delete(root.left,item);
         else if(root.key < item)
             root.right=delete(root.right,item);
         else {
             if(root.left==null) {
             Node temp=root.right;
             root=null;
             return temp;
         }
           else if(root.right==null) {
               Node temp=root.left;
               root=null;
               return temp;
            }
              Node min=minimum(root.right);
              root.key=min.key;
              delete(root.right,min.key);
          }
         return root;
     }
             
          
          

     public static void main(String[] args){
         Bst obj=new Bst();
         Node root=null;
         Scanner scan=new Scanner(System.in);
         
         for(String i:args){
             int a=Integer.parseInt(i);         
             root=obj.addnode(root,a);
         }
             obj.inorder(root);
             System.out.println();
         System.out.print("choose val fo deletion:-  ");
          int val=scan.nextInt();
           obj.delete(root,val);
           obj.inorder(root);
           System.out.println();

    }       
      
}

