#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void print_list(struct song_node *songlist){
  while(songlist != NULL){
    printf(" %s: %s |", songlist->artist , songlist->name);
    songlist = songlist->next;
  }
}

struct song_node *makeNode(char *name, char *artist){
  struct song_node *newsong = (struct song_node*) malloc(sizeof(struct song_node));
  strcpy(newsong->name, name);
  strcpy(newsong->artist, artist);
  return newsong;
}

struct song_node * insert_front(struct song_node *songlist, struct song_node *newsong){
  newsong->next = songlist;
  return newsong;
}

// struct song_node * free_list(struct song_node *mynode){
//   while(mynode != NULL){
//     struct song_node* holder = mynode;
//     free(holder);
//     holder = NULL;
//     mynode = mynode->next;
//   }
//   return mynode;
// }

// struct song_node * remove_node(struct song_node *front, int data){
//     struct song_node *curr = front;
//     struct song_node *prev = NULL;
//     while (curr != NULL) {
//       if(curr->i == data){
//         struct song_node * holder = curr;
//         if (prev == NULL) front = front->next;
//         else prev->next = holder->next;
//         free(holder);
//         holder = NULL;
//       }
//       prev = curr;
//       curr = curr->next;
//     }
//     return front;
// }
