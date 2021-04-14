#include "function.h"

void findByPrice(List* Basa){
    printf("enter price\n");
    int pr;
    scanf("%d",&pr);
    printf("\n");
    findPrice(Basa,pr);
}
///----------------------------------------------------------------------------------
void findByBrand(List *Basa){///
    printf("enter brand\n");
    char br[40];
    scanf("%s",br);
    printf("\n");
    findBrand(Basa,br);
}
///----------------------------------------------------------------------------------
void findByName(List *Basa){///
    printf("enter name\n");
    char nm[100];
    scanf("%s",nm);
    printf("\n");
    findName(Basa,nm);
}

///----------------------------------------------------------------------------------
void loading(List *Basa, char* filename){
    FILE* f=fopen (filename,"r");
    if (f==NULL){
        printf("            !!!   DATABASE CORRUPTED   !!!\n");
        exit(1);
    }

    int i,j;
    Basa->first=0;
    int price;
    char brand[40];
    char name[100];
    char mm;
    while(!feof(f)){
        Item* it=(Item*)malloc(sizeof(Item));
        fscanf(f,"%d",&price);
        if(price<0){
            free(it);
            break;
        }
        it->price=price;
        mm=fgetc(f);
        i=0;
        while ((mm=fgetc(f))!=':'){
            brand[i]=mm;
            i++;
        }
        brand[i]='\0';
        it->brand=(char*)malloc((i+1)*sizeof(char));
        for (j=0;j<=i;j++){
            it->brand[j]=brand[j];
        }
        i=0;
        while ((mm=fgetc(f))!='\n'){
            name[i]=mm;
            i++;
        }
        name[i]='\0';
        it->name=(char*)malloc((i+1)*sizeof(char));
        for (j=0;j<=i;j++){
            it->name[j]=name[j];
        }
        add(Basa,it);
        free(it);
    }
    fclose(f);
}

///---------------------------------------------------------------------------

void add2basa(List* Basa){
    int price;
    char brand[40];
    char name[100];
    char mm;
    Item* it=(Item*)malloc(sizeof(Item));
    int i,j;

    printf("enter product price \n");
    scanf("%d",&price);
    it->price=price;

    getchar();

    printf("enter product brand\n");
    i=0;
    while ((mm=getchar())!='\n'){
        brand[i]=mm;
        i++;
    }
    brand[i]='\0';
    it->brand=(char*)malloc((i+1)*sizeof(char));
    for (j=0;j<=i;j++){
        it->brand[j]=brand[j];
    }

    printf("enter product name\n");
    i=0;
    while ((mm=getchar())!='\n'){
        name[i]=mm;
        i++;
    }
    name[i]='\0';
    it->name=(char*)malloc((i+1)*sizeof(char));
    for (j=0;j<=i;j++){
        it->name[j]=name[j];
    }
    add(Basa,it);
    free(it);
}

///---------------------------------------------------------------------------------------

int deleteFromBasa(List* Basa){
    int price;
    char brand[40];
    char name[100];
    char mm;
    Item* it=(Item*)malloc(sizeof(Item));
    int i,j;

    printf("enter product price \n");
    scanf("%d",&price);
    it->price=price;

    getchar();

    printf("enter product brand\n");
    i=0;
    while ((mm=getchar())!='\n'){
        brand[i]=mm;
        i++;
    }
    brand[i]='\0';
    it->brand=(char*)malloc((i+1)*sizeof(char));
    for (j=0;j<=i;j++){
        it->brand[j]=brand[j];
    }

    printf("enter product name\n");
    i=0;
    while ((mm=getchar())!='\n'){
        name[i]=mm;
        i++;
    }
    name[i]='\0';
    it->name=(char*)malloc((i+1)*sizeof(char));
    for (j=0;j<=i;j++){
        it->name[j]=name[j];
    }
    int result = deleteFromList(Basa,*it);
    freeItem(*it);
    free(it);
    return result;
}

///---------------------------------------------------------------------

void deleteAllFromBasa(List* Basa){
    deleteAllFromList(Basa);
}

///-----------------------------------------------------------------------

void change(List* Basa){
    int result=deleteFromBasa(Basa);
    if (result==1){
        printf("now enter new product options\n");
        add2basa(Basa);
    }
}
