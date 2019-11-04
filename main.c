#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "library.h"
int main(){
  srand(time(NULL));
  printf("LINKED LIST TEST\n");
  printf("------------------------- \n\n");

  struct song_node *  end = NULL;
  end = insert_front(end, "paranoid android", "radiohead");
  printf("Testing insert_front: [radiohead: paranoid android] \n");
  print_list(end);
  printf("Testing insert_front: [pearl jam: even flow] \n");
  end = insert_front(end, "alive", "pearl jam");
  print_list(end);
  printf("Testing insert_front: [ac/dc: thunderstruck] \n");
  end = insert_front(end, "thunderstruck", "ac/dc");
  print_list(end);

  printf("------------------------- \n\n");
  printf("Testing print_list: \n");
  print_list(end);


  printf("------------------------- \n\n");
  end = orderInsert(end, "yellow ledbetter", "pearl jam");
  printf("Testing orderInsert: [pearl jam: yellow ledbetter] \n");
  print_list(end);
  end = orderInsert(end, "street spirit (fade out)", "radiohead");
  printf("Testing orderInsert: [radio head: street spirit (fade out)] \n");
  print_list(end);
  end = orderInsert(end, "time", "pink floyd");
  printf("Testing orderInsert: [pink floyd: time] \n");
  print_list(end);
  end = orderInsert(end, "even flow", "pearl jam");
  printf("Testing orderInsert: [pearl jam: even flow] \n");
  print_list(end);

  end = insert_front(end, "yellow ledbetter", "pearl jam");
  end = insert_front(end, "time", "pink floyd");
  end = insert_front(end, "alive", "pearl jam");
  end = insert_front(end, "street spirit (fade out)", "radiohead");

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
  struct song_node * one = makeNode( "even flow", "pearl jam");
  struct song_node * two = makeNode( "even flow", "pearl jam");
  struct song_node * three = makeNode( "alive", "pearl jam");
  struct song_node * four = makeNode("time", "pink floyd");
  printf("Testing songcmp: \n");
  printf("Comparing [pearl jam: even flow] to [pearl jam: even flow] \n");
  printf("%d\n", songcmp(one,two));
  printf("Comparing [pearl jam: even flow] to [pearl jam: alive] \n");
  printf("%d\n", songcmp(one, three));
  printf("Comparing Comparing [pearl jam: alive] to [pearl jam: even flow] \n");
  printf("%d\n", songcmp(three, one));
  printf("Comparing [pearl jam: even flow] to [pink floyd: time] \n");
  printf("%d\n", songcmp(one, four));


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

  printf("\nMusic Library Tests\n");
  printf("------------------------- \n\n");
  setTable();
  printf("Testing print_library\n");

  add_song("thunderstruck", "ac/dc");
  add_song("alive","pearl jam");
  add_song("yellow ledbetter", "pearl jam" );
  add_song("time", "pink floyd");
  add_song("even flow", "pearl jam" );
  add_song("peaches", "presidents of the united states of america");
  add_song("paranoid android", "radiohead" );
  add_song("street spirit (fade out)", "radiohead" );
  add_song("hello", "$324" );
  add_song("bye", "344" );
  print_songlib();
  // printf("------------------------- \n\n");
  //
  //
  // printf("Testing search_songlib\n");
  // printf("%s\n", "Looking for [radiohead:street spirit (fade out)]" );
  // struct song_node * found = search_song("street spirit (fade out)", "radiohead");
  // print_list(found);
  // printf("\n" );
  // printf("%s\n", "Looking for [$324:hello)]" );
  // found = search_song("hello", "$324");
  // print_list(found);
  // printf("\n" );
  // printf("------------------------- \n\n");
  //
  // printf("Testing print_letter\n");
  // printf("%s\n", "z list" );
  // print_letter('z');
  // printf("\n" );
  // printf("%s\n", "p list" );
  // print_letter('p');
  // printf("\n" );
  // printf("%s\n", "misc list" );
  // print_letter('3');
  // printf("------------------------- \n\n");
  //
  // printf("Testing search_artist\n");
  // printf("%s\n", "Looking for songs by [pearl jam]" );
  // struct song_node * artist = search_artist("pearl jam");
  // print_list(artist);
  // printf("\n" );
  // printf("%s\n", "Looking for songs by [pink floyd]" );
  // artist = search_artist("pink floyd");
  // print_list(artist);
  // printf("\n" );
  // printf("%s\n", "Looking for songs by [pink floyd]" );
  // artist = search_artist("bob dylan");
  // print_list(artist);
  // printf("------------------------- \n\n");
  //
  // printf("Testing print_artist\n");
  // printf("%s\n", "Printing [pearl jam]:" );
  // print_artist("pearl jam");
  // printf("%s\n", "Printing [ac/dc]:" );
  // printf("\n");
  // print_artist("ac/dc");
  // printf("------------------------- \n\n");
  //
  // printf("%s\n", "Current Library:" );
  // print_songlib();
  // printf("\n" );
  // printf("%s\n", "removing: [pearl jam: alive]" );
  // remove_song("alive","pearl jam");
  // print_songlib();
  // printf("\n" );
  // printf("%s\n", "removing: [radiohead: street spirit (fade out)]" );
  // remove_song("street spirit (fade out)","radiohead");
  // print_songlib();
  // printf("------------------------- \n\n");
  //
  // printf("%s\n", "shuffle" );
  // print_shuffle();
  // printf("------------------------- \n\n");
  //
  // printf("Testing free_lib\n");
  // free_lib();
  // printf("------------------------- \n\n");
  //
  // printf("%s\n", "Current Library:" );
  // print_songlib();
  // printf("------------------------- \n\n");
}
