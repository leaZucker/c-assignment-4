#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "frequency.h"

void addWord(node** root ,char* word){
    node** p = root;
    int index ;
    for(int i= 0;word[i];i++){
        if(*p){
        index = CHAR_TO_INDEX(word[i]);
        if(index>25||index<0) index = IT_WAS_CAPITAL(word[i]);
        if(index>=0&&index<26){
        if ((*p)->children[index] != NULL) {
            (*p)->children[index]->count++; ;
            p = &((*p)->children[index]);
        }
        else{
            node *n1 = (node*)malloc(sizeof(struct node));
            if(!n1){
                freeTrie(*p);
                exit(1);
            }
            n1->letter = word[i];
            n1->count = 1;
            for(int i = 0;i<NUM_LETTERS;i++)
                n1->children[i] = NULL;
            (*p)->children[index] = n1;
            p = &((*p)->children[index]);
        }
        }
        }
        else{
          freeTrie(*root);  
          exit(1);
        }
    }
    if((*p)->children[26] == NULL){
    node *n2 = (node*)malloc(sizeof(struct node));
    if(!n2){
        freeTrie(*p);
        exit(1);
    }
    n2->letter = '$';
    n2->count = 0;
    for(int i = 0;i<NUM_LETTERS;i++)
        n2->children[i] = NULL;
    (*p)->children[26] = n2;
    }
}
void printWordsMin(node* root, char *word){
    if(root){
        if(root->children[26]!=NULL)
            printf("%s, %ld\n",word,root->count);
        int len = strlen(word);
        for(int i =0;i<NUM_LETTERS-1;i++){
            if(root->children[i]!=NULL){
                if(len<WORD)
                    word[len] = root->children[i]->letter;
                else break;
                printWordsMin(root->children[i], word);
                for(int i = len;word[i];i++)
                    word[i] = 0;
            }
        }
    }
}
void printWordsMax(node* root, char *word){
    if(root){
        if(root->children[26]!=NULL)
            printf("%s, %ld\n",word,root->count);
        int len = strlen(word);
        for(int i = NUM_LETTERS-2;i>=0;i--){
            if(root->children[i]!=NULL){
                if(len<WORD)
                    word[len] = root->children[i]->letter;
                else break;
                printWordsMax(root->children[i], word);
                for(int i = len;word[i];i++)
                    word[i] = 0;
            }
        }
    }
}
void freeTrie(node *root){
    if(root){
        for(int i =0;i<NUM_LETTERS;i++){
            if(root->children[i]!=NULL){
                freeTrie(root->children[i]);
            }
        }
        free(root);
    }
}

