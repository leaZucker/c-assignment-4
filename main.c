#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "frequency.h"

int main(int argc,char **argv){
    node *head = (node*)malloc(sizeof(struct node));
    if(head){
        head->letter = '$';
        head->count = 0;
         for(int i = 0;i<NUM_LETTERS;i++)
            head->children[i] = NULL;
        char word[WORD];
         for(int i=0;i<WORD;i++){
                word[i] =0;
            }
        node **root = &head; 
        int count = 0;
        while (count < WORD) {
            if (scanf("%c", &word[count] )!= EOF) {
                if ( word[count] == '\r' || word[count] == '\t' || word[count] == ' '|| word[count] == '\n') {
                    addWord(root, word);
                    count = 0;
                    for(int i=0;i<WORD;i++){
                        word[i] =0;
                    }
                }
                else
                    count++;
            }
            else
                break;
            }
        char w[WORD];
        for(int i=0;i<WORD;i++){
            w[i] =0;
        }
        if(!argv[1]){
        printWordsMin(head,w);
        }
        else{
        printWordsMax(head,w);
        }
        freeTrie(head);
        return 0;
    }
    return 1;
}