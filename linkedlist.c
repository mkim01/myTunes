#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void print_list(struct song_node *songlist){
  while(songlist != NULL){
    printf(" %s: %s | ", songlist->artist , songlist->name);
    songlist = songlist->next;
    }
      printf("\n" );
}

struct song_node * makeNode( char *name, char *artist){
  struct song_node *newsong = (struct song_node*) malloc(sizeof(struct song_node));
  strcpy(newsong->name, name);
  strcpy(newsong->artist, artist);
  return newsong;
}

struct song_node * insert_front(struct song_node *songlist, char *name, char *artist){
  struct song_node *newsong = makeNode(name, artist);
  newsong->next = songlist;
  return newsong;
}

struct song_node * get(struct song_node * songlist, char * name, char * artist){
  struct song_node * current = songlist;
  while (current != NULL){
    if (strcmp(current -> artist, artist ) == 0){
      if (strcmp(current -> name, name ) ==0){
        printf("Arist found!\n");
        return current;
      }
    }
    current = current -> next;
  }
  printf("Song not found.\n");
  return NULL;
}

struct song_node * getFirst(struct song_node * songlist,char * artist){
  struct song_node * current = songlist;
  while (current != NULL){
    if (strcmp(current -> artist, artist ) == 0){
        return current;
    }
    current = current -> next;
  }
  printf("Song not found.\n");
  return NULL;
}


struct song_node * remove_node(struct song_node *front,char * name,char * artist) {
    struct song_node * prev = NULL;
    struct song_node * curr = front;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0 && strcmp(curr->artist, artist) == 0) {
            if (prev == NULL) {
                struct song_node * temp = curr->next;
                free(curr);
                return temp;
            }
            prev->next = curr->next;
            free(curr);

        }
        prev = curr;
        curr = curr -> next;
    }
    return front;
}


// struct song_node * order(struct song_node *songlist,char * name,char * artist){
//   struct song_node * newnode = makeNode(name, artist);
//   struct song_node * curr = songlist;
//   struct song_node * prev = NULL;
//   while (curr != NULL){
//     if (strcmp(curr -> name, name)
//   }
// }
// //
// struct song_node * getfirst(struct song_node * songlist, char * artist){
//   struct song_node * current = songlist;
//   while (current != NULL){
//     if (strcmp(songlist -> artist, artist ) == 0){
//       return current;
//     }
//     current = current -> next;
//   }
//
//   return current;
// }
struct song_node * free_list(struct song_node *mynode){
  while(mynode != NULL){
    struct song_node* holder = mynode;
    printf("Freeing node: %s %s\n", holder->artist, holder-> name);
    free(holder);
    holder = NULL;
    mynode = mynode->next;
  }
  return mynode;
}

int length(struct song_node *mynode ){
  struct song_node * curr = mynode;
  int length = 0;
  while (curr != NULL) {
      length ++;
      curr = curr -> next;
  }
  return length;
}

void print_song(struct song_node * song) {
    printf("%s: %s | \n", song->artist, song->name);
}

struct song_node * findRandom(struct song_node * mynode){
  struct song_node * curr = mynode;
  int x = length(mynode);
  if (x != 0){
  int counter = rand() % x;
    while( counter >1 ){
      curr = curr -> next;
      counter--;
}
return curr;
}
return curr;
}
