#include<stdio.h>
#include<stdlib.h>

/* structure foe linked list*/
typedef struct link_list {
     int data;
     struct link_list *next;
}node_of_linklist;
typedef node_of_linklist *link;

/* structure for BST */
typedef struct Node {
     int data;
     struct Node *left,*right;
}node;
typedef node *list;

/* creating a new node */
list new_node(int element) {
    list temp=(list)malloc(sizeof(node*));
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
}

/* insertion according to BST rule */
list insert_node(list root,int element) {
     if(root==NULL) return new_node(element) ;
      
     if(root->data >= element)
         root->left=insert_node(root->left,element);

     else if(root->data <= element)
         root->right=insert_node(root->right,element);
      
    return root; 
}
void inorder(list root) {
    if(root!=NULL) {

    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right); 
    }
}

main() {
   list root=NULL,head;
   int element,n,i;

   printf("enter the number of element you wAnT TO ENTER");
   scanf("%d",&n);

   link start,temp;

   start=(link)malloc(sizeof(node_of_linklist*));
   temp=start;

   for(i=0;i<n-1;i++) {
       scanf("%d",&start->data);
       start=start->next=(link)malloc(sizeof(node_of_linklist*)); 
   }
   scanf("%d",&start->data);
   start->next=NULL;
     
   root= insert_node(root,temp->data);
   head=root;
   while(temp->next!=NULL) {
       temp=temp->next;
       insert_node(root,temp->data);
       
   }
   inorder(root);
   
}
