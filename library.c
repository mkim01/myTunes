#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "library.h"

void setTable(){
  int x;
  for (x = 0; x < sizeof(table)/sizeof(table[0]); x++){
    table[x] = NULL;
  }
}

void add_song( char * name, char * artist) {
  int letter;
  if (strlen(artist) > 0){
    letter = artist[0] - 'a';
    if (letter < 0){
      letter = 26;
    }
    table[letter] = orderInsert(table[letter], name, artist);
  }
  else{
    letter = 26;
    table[letter] = orderInsert(table[letter], name, artist);
  }
}


void print_songlib(){
  int letter;
  for (letter = 0; letter < sizeof(table)/sizeof(table[0]); letter++){
   if (letter == 26){
     if (table[letter] != NULL){
     printf("%s: ", "misc songs" );
     print_list(table[letter]);
   }
   }
   else{
     if (table[letter] != NULL){
       printf("%c: ", letter+'a');
       print_list(table[letter]);
}
      }
    }
  }



struct song_node *search_song(char * name, char * artist) {
    int letter = artist[0] - 'a';
    if (letter < 0){
      letter = 26;
    }

    return get(table[letter], name, artist);

  }

void print_letter(char letter){
    int index = letter - 'a';
    if (index < 0) {
      index = 26;
    }
    if (table [index] == NULL){
      printf("No artists with this letter\n");
    }
    else{
      print_list(table[index]);
    }
  }

struct song_node *search_artist(char * artist){
  int letter = artist[0] - 'a';
  if (letter < 0){
    letter = 26;
  }
  return getFirst(table[letter], artist);
}

void remove_song( char * name, char * artist){
  int letter = artist[0] - 'a';
  if (letter < 0){
    letter = 26;
  }
  table[letter] = remove_node(table[letter],name, artist);
}

void free_lib(){
  int letter;
  for (letter = 0; letter < sizeof(table)/sizeof(table[0]); letter++){
    table[letter] = free_list(table[letter]);
  }
}
void print_artist(char * artist){
  struct song_node * song = search_artist(artist);
    while (song != NULL && strcmp(song -> artist, artist) == 0){
      print_song(song);
      song = song -> next;
    }
}

int libsize(){
  int x;
  int counter = 0;
  struct song_node * current;
  for (x = 0; x < sizeof(table)/sizeof(table[0]); x++){
    counter += length(table[x]);
  }
  return counter;
}



void shuffle(){
  struct song_node * curr;
  int x;
  int length = libsize();
  if (length != 0){
    length = rand() % length;
    for (x = 0; x < sizeof(table)/sizeof(table[0]); x++){
      if (table[x] != NULL){
        curr = table[x];
      while (curr != NULL){
        if (length== 0){
          print_song(curr);
          return;
        }
        curr = curr->next;
        length --;
        }
      }

    }
  }
}
void print_shuffle(){
  shuffle();
  shuffle();
  shuffle();

}
