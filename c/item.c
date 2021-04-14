#include "item.h"
void printt(Item i){
    printf("%5d B:%20s\tN:%40s\n",i.price,i.brand,i.name);
}

void freeItem(Item i){
    free(i.brand);
    free(i.name);
}
