#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "freq.h"

//This method gets a char pointer and an integer and will print the word and the number of times it was inserted into the TRIE.
void print(char str[],int count)
{
    printf("%s\t%d\n",str,count);
}
//This method gets a char pointer and will basically strings the chars together and then return the word length.
int get_word(char str[])
{
    int length=0;
    char letter;
    char* word=str;
   
    do
    {
        if(scanf("%c",&letter)==EOF)return 0;
	if(letter>='A'&&letter<='Z') letter+=32;  //In case of an uppercase letter.   
	if(letter>='a'&&letter<='z') 					 
        {
            *(word++)=letter;
             length++;
        }
    }while(letter!='\n'&&letter!='\t'&&letter!=' ');

    return length;
}
//This method will create a new struct node and return his pointer.
struct node* new_node()
{
    node* temp=(node*)malloc(sizeof(node));
    for(int i=0;i<NUM_LETTERS;i++)
        temp->_child[i]=NULL;
   
    temp->_isWord=false;
    temp->_count=0;
   
    return temp;
}
//This method will insert a new node to the TRIE data structure, its get as an argument the root node pointer, a pointer to the key(char), and the word length.
void insert_node(node* root,char* key,int length)
{
    int level;
    struct node* temp=root;
   
    for(level=0;level<length;level++)
    {
        int index=key[level]-'a';
        if(temp->_child[index]==NULL)
        {
            temp->_child[index]=new_node();
       
        }
        temp=temp->_child[index];
       
    }
    if(temp->_isWord)
        temp->_count++;
    else
    {
        temp->_isWord=true;
        temp->_count=1;
    }
}
//This method will return true or false base on the isWord state. true = end of word, false = not the end of the word.
bool is_word(node* root)
{
    return root->_isWord;
}

//This recursive method will display the TRIE in a up going lexicographic order.
void display(node* root,char str[],int level)
{
    if(is_word(root))
    {
        str[level]='\0';
        print(str,root->_count);
    }
    int i;
    for(i=0;i<NUM_LETTERS;i++)
    {
        if(root->_child[i])
        {
            str[level]=i+'a';
            display(root->_child[i],str,level+1);
        }
    }
   
}
//This recursive method will display the TRIE in a down going lexicographic order.
void revers(node* root,char str[],int level)
{
    if(is_word(root))
    {
        str[level]='\0';
        print(str,root->_count);
    }
   int i;
    for(i=NUM_LETTERS-1;i>=0;i--)
    {
        if(root->_child[i])
        {
            str[level]=i+'a';
            revers(root->_child[i],str,level+1);
        }
 
    }
   
}
//This method will initiate the TRIE data structure.
struct node* bulid_trie()
{
    node* root=new_node();
    char keys[NUM_LETTERS];
    int length_key=0;
   
    do
    {
     length_key=get_word(keys);
     if(length_key!=0)
     insert_node(root,keys,length_key);
    }while(length_key!=0);
   
    return root;
}
//This method will free the allocating memory in the system. it is called right before the program ends.
void free_trie(node* root)
{
    node* temp=root;
    int i;
    for(i=NUM_LETTERS-1;i>=0;i--) if(temp->_child[i]) free_trie(temp->_child[i]); 		        
    free(root);
}
