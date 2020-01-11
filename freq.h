#ifndef FREQ_H
#define FREQ_H
#define NUM_LETTERS ((int)26)
typedef struct node //Declaring the struct node that we will use in our code.
{
 char _letter;
 long _count;
 struct node* _child[NUM_LETTERS];
 bool _isWord;
}node;
void print(char str[],int count);
int get_word(char str[]);
struct node* new_node();
void insert_node(node* root,char* key,int length);
bool is_word(node* root);
void display(node* root,char str[],int level);
void revers(node* root,char str[],int level);
struct node* bulid_trie();
void free_trie(node* root);
#endif
