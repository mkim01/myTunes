#include "linkedList.h"
void add_song(struct song_node *songlist [27], char name[], char artist []) ;
struct song_node *search_song(struct song_node *songlib [27], char name [], char artist []) ;
struct song_node *search_artist(struct song_node *songlib [27], char artist []) ;
void print_letter(struct song_node * songlib [27], char letter) ;
void print_song_artist(struct song_node * songlib [27], char artist []) ;
void print_songlib(struct song_node * songlib [27]);
void print_suffle(struct song_node *songlib[27]);
void remove_song(struct song_node *songlist [27], char name[], char artist []) ;
void free_lib(struct song_node *front, char *artist);
