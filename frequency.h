#ifndef __TRIE__
#define __TRIE__
    #define NUM_LETTERS ((int)27)
    #define WORD 50 
    #define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
    #define IT_WAS_CAPITAL(c) ((int)c - (int)'A')

    typedef enum {FALSE=0, TRUE=1} boolean;
    typedef struct node {
        char letter;
        long unsigned int count;
        struct node* children[NUM_LETTERS];
    } node;

    void addWord(node** root ,char* word);

    void printWordsMin(node* root, char *word);

    void printWordsMax(node* root, char *word);

    void freeTrie(node *root);

#endif