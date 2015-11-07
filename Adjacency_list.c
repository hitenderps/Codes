#include <stdio.h>
#include <stdlib.h>

typedef struct graphnode {
     int name;
     struct graphnode *next;
}node;
typedef node* graph;


void addNode(graph G[],int startNode, int endNode) {
// creating a new linked list which is to be added
     graph tmp=(graph)malloc(sizeof(node*));
     tmp->name=G[endNode]->name;
     tmp->next=G[startNode]->next;
     G[startNode]->next=tmp;
}

void printGraph(graph G[], int numofnodes) {
     int i;
     graph tmp;
     for(i=0;i<numofnodes;i++) {
          tmp=G[i];
          printf("%d ",i);    

          while(tmp!=NULL) {   
              printf("%d->",tmp->name);
              tmp=tmp->next;
          }
           printf("\n");
      }
}

int main(void) {
     int numofnodes;
     printf("Enter the number of nodes: ");
     scanf("%d",&numofnodes);


     graph arrayOfVertices[numofnodes];
     int i;     

     for(i=0;i<numofnodes;i++) {
         arrayOfVertices[i]=(graph)malloc(sizeof(node*));
         arrayOfVertices[i]->name=rand()%10;
         arrayOfVertices[i]->next=NULL;
     }


     addNode(arrayOfVertices,0,1);
     addNode(arrayOfVertices,1,3);
     printGraph(arrayOfVertices,numofnodes);


}
