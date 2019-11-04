#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void print_list(struct song_node *songlist){
  if (songlist == NULL){
    printf("%s" , "EMPTY LIST");
  }
  while(songlist != NULL){
    printf("%s: %s | ", songlist->artist , songlist->name);
    songlist = songlist->next;
    }
      printf("\n" );
}

struct song_node * makeNode( char *name, char *artist){
  struct song_node * new_node = malloc(sizeof(struct song_node));
  strncpy(new_node->name, name, sizeof(new_node->name));
  strncpy(new_node->artist, artist, sizeof(new_node->artist));
  new_node -> next = NULL;
  return new_node;
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
        printf("Song found!\n");
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


struct song_node * remove_node(struct song_node *front, char * name, char * artist) {

    struct song_node * prev = NULL;
    struct song_node * current = front;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && strcmp(current->artist, artist) == 0) {
            if (prev == NULL) {
                struct song_node * temp = current->next;
                free(current);
                return temp;
            }
            prev->next = current->next;
            free(current);
            return front;
        }

        prev = current;
        current = current -> next;
    }

    return front;
}

int songcmp(struct song_node *one, struct song_node *two){
  if (strcmp(one -> artist,two -> artist) > 0){
    return 1;
  }
  if (strcmp(one -> artist,two -> artist) < 0){
    return -1;
  }
  else{
    if  (strcmp(one -> name,two -> name) > 0){
      return 1;
    }
    if  (strcmp(one -> name,two -> name) < 0){
      return -1;
    }
  }
  return 0;
}


struct song_node * orderInsert(struct song_node *songlist,char * name,char * artist){
  struct song_node * newnode = makeNode(name, artist);
  struct song_node * curr = songlist;
  struct song_node * prev = NULL;
  while(curr != NULL){
  if (songcmp(newnode,curr) < 0 || songcmp(newnode,curr) == 0 ){
      if (prev == NULL){
        newnode -> next = songlist;
        return newnode;
      }
      prev -> next = newnode;
      newnode -> next = curr;
      return songlist;
  }
  prev = curr;
  curr = curr -> next;
}

if (prev == NULL){
return newnode;
}
prev -> next = newnode;
return songlist;
}




struct song_node * free_list(struct song_node * list) {
    struct song_node * current = list;
    struct song_node * next = current;
    while (current != NULL) {
        next = current->next;
        printf("Freeing node: ");
        print_song(current);
        printf("\n");
        free(current);
        current = next;
    }
    return NULL;
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
