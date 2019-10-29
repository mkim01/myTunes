struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct node * mynode);
struct node * insert_front(struct node * mynode, int value);
struct node * free_list(struct node * mynode);
struct node * remove_node(struct node *front, int data);
