#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

int main(){
  srand(time(NULL));
  printf("LINKED LIST TEST\n");
  printf("------------------------- \n\n");

  struct song_node *  end = NULL;
  end = insert_front(end, "thunderstruck", "ac/dc");
  end = insert_front(end, "alive", "pearl jam");
  end = insert_front(end, "even flow", "pearl jam");
  end = insert_front(end, "yellow ledbetter", "pearl jam");
  end = insert_front(end, "time", "pink floyd");
  end = insert_front(end, "paranoid android", "radiohead");
  end = insert_front(end, "street spirit (fade out)", "radiohead");
  printf("Testing print_list: \n");
  print_list(end);

  printf("------------------------- \n\n");
  printf("Testing print_song: \n");
  print_song(end);

  printf("------------------------- \n\n");
  printf("Testing find_artist: \n");
  printf("Looking for time by [pink floyd]: \n");
  print_list(get(end,"time", "pink floyd"));
  printf("Looking for thunderstruck by ac/dc: \n");
  print_list(get(end,"thunderstruck", "ac/dc"));
  printf("Looking for thunder by by Imagine Dragons: \n");
  print_list(get(end,"thunder", "Imagine Dragons"));

  printf("------------------------- \n\n");
  printf("Testing getFirst: \n");
  printf("Looking for song by pearl jam: \n");
  print_song(getFirst(end,"pearl jam"));



  printf("------------------------- \n\n");
  printf("Current list:\n");
  print_list(end);
  printf("Removing: street spirit (fade out) by radiohead\n");
  end = remove_node(end,"street spirit (fade out)", "radiohead" );
  print_list(end);
  printf("Removing: alive by peral jam\n");
  end = remove_node(end, "alive", "pearl jam");
  print_list(end);
  printf("Removing: thunderstruck by ac/dc\n");
  end = remove_node(end,"thunderstruck", "ac/dc" );
  print_list(end);
  printf("\n");


  printf("------------------------- \n\n");
  printf("Testing Random \n");
  print_list(end);
  struct song_node * random = findRandom(end);
  print_song(random);
  random = findRandom(end);
  print_song(random);
  random = findRandom(end);
  print_song(random);

  printf("------------------------- \n\n");
  printf("Testing free_List \n");
  end = free_list(end);
  print_list(end);


}
