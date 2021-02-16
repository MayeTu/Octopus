#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdlib.h>
#include "list.h"

void findByPrice(List* Basa);

void findByBrand(List *Basa);

void findByName(List *Basa);

void add2basa(List* Basa);

int deleteFromBasa(List* Basa);

void deleteAllFromBasa(List* Basa);

void loading(List* L, char* filename);

void change(List *Basa);

#endif // FUNCTION_H_INCLUDED
