#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "function.h"

int main(int argc, char** argv)
{
    if(argc<2) {
      printf("Error: Provide database filename!\n");
      return 1;
    }
    List* Basa=(List*)malloc(sizeof(List));

    loading(Basa, argv[1]);

    printf ("  WELCOME TO PERFUME STORE\n");

    char num=0;char musor;
    while (num!='9'){

        printf("\n");
        printf("      Main Menu\n");
        printf("1) view all products \n");
        printf("2) show all products by name \n");
        printf("3) show all products by price \n");
        printf("4) show all products by brand \n");
        printf("5) add product \n");
        printf("6) delete product \n");
        printf("7) edit product \n");
        printf("8) delete all products \n");
        printf("9) exit \n");
        printf("\n");
        printf(">");

        while((num=getchar())=='\n'){}
        musor=getchar();
        switch (num){
            case '1':
                print(Basa);
                break;
            case '2':
                findByName(Basa);
                break;
            case '3':
                findByPrice(Basa);
                break;
            case '4':
                findByBrand(Basa);
                break;
            case '5':
                add2basa(Basa);
                break;
            case '6':
                deleteFromBasa(Basa);
                break;
            case '7':
                change(Basa);;
                break;
            case '8':
                deleteAllFromBasa(Basa);
                break;
            case '9':
                break;
            default:
                printf("please choose correct number");
        }
    }
    write2file(Basa, argv[1]);
    deleteAllFromBasa(Basa);
    free(Basa);
    printf("\t Have A Good Day!\n\n");
    return 0;
}
