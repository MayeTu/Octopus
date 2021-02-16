#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct item{
    int price;
    char* name;
    char* brand;
};
typedef struct item Item;

void printt(Item i);

void freeItem(Item i);

#endif // ITEM_H_INCLUDED
