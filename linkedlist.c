#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void print_list(struct node *mynode){
  printf("[");
  while (mynode != NULL){
    printf("%d ", mynode->i);
    mynode = mynode -> next;
  }
  printf("]");
}

struct node * insert_front(struct node *mynode, int value){
  struct node *newnode = (struct node *) malloc(sizeof(struct node));
  newnode->i = value;
  newnode->next = mynode;
  return newnode;
}

struct node * free_list(struct node *mynode){
  while(mynode != NULL){
    struct node* holder = mynode;
    free(holder);
    holder = NULL;
    mynode = mynode->next;
  }
  return mynode;
}

struct node * remove_node(struct node *front, int data){
    struct node *curr = front;
    struct node *prev = NULL;
    while (curr != NULL) {
      if(curr->i == data){
        struct node * holder = curr;
        if (prev == NULL) front = front->next;
        else prev->next = holder->next;
        free(holder);
        holder = NULL;
      }
      prev = curr;
      curr = curr->next;
    }
    return front;
}
