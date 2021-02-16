#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* next;
    Item data;

};
typedef struct node Node;

struct list {
    Node* first;

};
typedef struct list List;

void add(List* L, Item* foradd);

void print(List* L);

void findPrice(List* L,int pr);

int deleteFromList(List* L, Item toDelete);

void write2file(List* L, char* filename);

void findBrand(List* L,char br[40]);

void findName(List* L,char nm[100]);

void deleteAllFromList(List* L);

#endif // LIST_H_INCLUDED
