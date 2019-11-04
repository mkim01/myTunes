#ifndef MUSIC
#define MUSIC
#include "linkedList.h"
struct song_node * table[27];
void setTable();
void add_song( char * name, char * artist) ;
struct song_node *search_song(char * name, char * artist) ;
struct song_node *search_artist(char * artist);
void print_letter(char letter) ;
void print_artist(char * artist) ;
void print_songlib();
void print_shuffle();
void shuffle();
void remove_song( char * name, char * artist) ;
void free_lib();
int libsize();
#endif
