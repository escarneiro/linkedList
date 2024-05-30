#include "linkedList.h"
#include <string.h>


/* consulta ultimo elemento */
listElement * peek(linkedList * LL ){
    if(LL->last!=NULL)
        return LL->last;
    else
        return LL->head;

}



void add (linkedList * LL,  char * key, int value){

    struct listElement *LE = (struct listElement*) malloc(sizeof(struct listElement));
    LE->value=value;
    //lz->key=key;
    strcpy(LE->key,key);

    if(LL->head==NULL){
        LL->head=LE;
        LL->head->nextLE=NULL;
        LL->curr_size+=1;

    }else
    {
        listElement * lz = LL->head;

       //procura ultimo elemento
        while(lz->nextLE!=NULL)
            lz=lz->nextLE;

        lz->nextLE=LE;
        LE->nextLE=NULL;
        LL->last=LE;
        LL->curr_size+=1;

    }

}


//* Busca um elemento na lista por 'key' *//
listElement * search(linkedList * LL, const char * key){
        listElement * lz = LL->head;
        if(lz==NULL)
            return NULL;
        else{
            while(lz->nextLE!=NULL){
                if(strcmp(lz->key,key)==0)
                   return lz;
                else
                    lz=lz->nextLE;
            }

        }

}

/* remove o elemento com chave 'key' da lista */
void remKey(linkedList * LL, const char * key){
        listElement * lz = LL->head;
        if(lz==NULL)
            return NULL;
        else{
            while(lz->nextLE!=NULL){
                listElement * ly = lz->nextLE;
                if(strcmp(ly->key,key)==0){
                    lz->nextLE=ly->nextLE;
                    LL->curr_size-=1;
                    return;
                }
                else
                    lz=lz->nextLE;
            }

        }

}


/* remove ultimo */
void remLast(linkedList * LL ){
        if(LL->head!=NULL&&LL->head->nextLE==NULL){
            LL->curr_size=0;
            LL->head=NULL;
            LL->last=NULL;
        }

        if (LL->head==NULL)
            return;
        else{

            listElement * lz = LL->head;

            while(lz->nextLE!=LL->last)
                lz=lz->nextLE;

            lz->nextLE=NULL;
            LL->last=lz;
            LL->curr_size-=1;
        }

}


void initialize(linkedList * LL ){
    LL->curr_size=0;
    LL->head=NULL;
    LL->last=NULL;

}

/* imprime a lista */
void printList(linkedList * LL){
    listElement * LE = LL->head;
    int i=0;
    printf("Lista: tamanho %d \n",LL->curr_size);
    while (LE!=NULL){

        printf("%d::   { %10s , %3d }\n",i,LE->key,LE->value);
        LE=LE->nextLE;
        i++;
    }


}

/* imprime heead e last */
void printHL(linkedList * LL){
    listElement * head = LL->head;
    printf("HEAD %d\n",head->value);
    listElement * last = LL->last;
    printf("LAST %d\n",last->value);
}
