struct song_node{
  char artist[100];
  char name[100];
  struct song_node *next;
};

void print_list(struct song_node *songlist);
struct song_node * insert_front(struct song_node *songlist, char *name, char *artist);
struct song_node * makeNode( char *name, char *artist);
struct song_node * order(struct song_node *songlist);
struct song_node * get(struct song_node * songlist, char * name, char * artist);
// struct song_node * free_list(struct song_node * mynode);
struct song_node * remove_node(struct song_node *front,char * name,char * artist);
struct song_node * free_list(struct song_node *mynode);
struct song_node * getFirst(struct song_node * songlist,char * artist);
int length(struct song_node *mynode );
struct song_node * findRandom(struct song_node * mynode);
void print_song(struct song_node * song);
