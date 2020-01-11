#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "freq.h"

//Main method to initiate the entire program.
int main(int argc, char* argv[])
{
    node* root=bulid_trie();
    int level=0;
    char str[NUM_LETTERS];
    if(argc == 2 && *(argv[1]) == 'r') revers(root,str,level);    
    else if (argc == 1) display(root,str,level);
    else printf("Something went wrong with the arguments\n");
    free_trie(root);
    return 0;
}
