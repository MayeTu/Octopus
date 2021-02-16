#include "util.h"
#include "list.h"

///----------------------------------------------------------------------------------
void add(List *L,Item *foradd){
    if (L->first==0){
        L->first=(Node*)malloc(sizeof (Node));
        L->first->data = *foradd;
        L->first->next=0;
    }
    else{
        Node *tmp=L->first;
        while(tmp->next!=0){
            tmp=tmp->next;
        }
        tmp->next=(Node*)malloc(sizeof (Node));
        tmp->next->data = *foradd;
        tmp->next->next=0;
    }
}
///----------------------------------------------------------------------------------
void print(List *L){
    Node *tmp=L->first;
    while (tmp!=0){
        printt(tmp->data);
        tmp=tmp->next;
    }
}
///----------------------------------------------------------------------------------
void findPrice(List* L,int pr){
    Node *tmp=L->first;
    int k=0;
    while (tmp!=0){
        if (tmp->data.price==pr){
                printt(tmp->data);
                k=1;
        }
        tmp=tmp->next;
    }
    if (k==0){
        printf("THERE IS NO SUCH PRODUCTS\n");
    }
}
///----------------------------------------------------------------------------------
int deleteFromList(List* L, Item toDelete){
    Node *tmp=L->first;
    //printf("---");
    //printt(tmp->data);
    //printt(toDelete);
    //printf("%i %i\n", stringCompare(tmp->data.brand, toDelete.brand ), stringCompare(tmp->data.name,  toDelete.name));


    if (tmp->data.price==toDelete.price &&
            stringCompare(tmp->data.brand, toDelete.brand )==0 &&
            stringCompare(tmp->data.name,  toDelete.name  )==0 )

    {
            Node *remove = L->first;
            L->first = L->first->next;
            freeItem(remove->data);
            free(remove);
            return 1;
    }

    Node *prev=tmp;
    tmp = prev->next;
    while (tmp!=0){
        //printf("---\n");
        //printt(tmp->data);
        //printt(toDelete);

        if (tmp->data.price==toDelete.price &&
            stringCompare(tmp->data.brand, toDelete.brand )==0 &&
            stringCompare(tmp->data.name,  toDelete.name  )==0 )
        {
            Node *remove = tmp;
            prev->next = tmp->next;
            freeItem(remove->data);
            free(remove);
            return 1;

        }
        prev = tmp;
        tmp =prev->next;
    }
    printf("THERE IS NO SUCH PRODUCT\n");
    return 0;
}

///----------------------------------------------------------------------------------
void write2file(List* L, char* filename){
    FILE* f=fopen(filename,"w");
    Node *tmp=L->first;
    while (tmp!=0){
        fprintf (f,"%d:%s:%s\n",tmp->data.price,tmp->data.brand,tmp->data.name);
        tmp=tmp->next;
    }
    fprintf(f,"-1");
    fclose(f);

}
///----------------------------------------------------------------------------------
void deleteAllFromList(List* L){
    Node* tmp = L->first;
    while(L->first != 0){
        tmp = L->first->next;
        freeItem(L->first->data);
        free(L->first);
        L->first=tmp;
    }
    return;
}
///----------------------------------------------------------------------------------
void findBrand(List* L,char br[40]){///
    Node *tmp=L->first;
    int k=0;
    while (tmp!=0){
        if (stringCompare(tmp->data.brand,br)==0){
            printt(tmp->data);
            k=1;
        }
        tmp=tmp->next;
    }
    if (k==0){
        printf("THERE IS NO SUCH PRODUCTS\n");
    }
}
///----------------------------------------------------------------------------------
void findName(List* L,char nm[100]){///
    Node *tmp=L->first;
    int k=0;
    while (tmp!=0){
        if (stringCompare(tmp->data.name,nm)==0){
            printt(tmp->data);
            k=1;
        }
        tmp=tmp->next;
    }
    if (k==0){
        printf("THERE IS NO SUCH PRODUCTS\n");
    }
}
///----------------------------------------------------------------------------------
