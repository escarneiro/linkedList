#include <stdio.h>
#include <stdlib.h>


/*

    linkedlist.h
    define estruturas para lista encadeada

 */



 /* Elemento de lista, inspirado em mapa {k,v}, com referencia para o proximo*/
 typedef struct listElement{

    char key[10];
    int  value;
    struct listElement * nextLE;

} listElement;



/* A lista em si */
 typedef struct linkedList{

    int curr_size;
    listElement * head; //primeiro elemento
    listElement * last; //ultimo elemento

}linkedList;

/* consulta ultimo elemento */
listElement * peek(linkedList * LL );


/* insere */
//void add(linkedList * LL, listElement *  LE);
void add (linkedList * LL,  char * key, int value);

/* busca */
listElement * search(linkedList * LL, const char * key);

/* remove o elemento com chave 'key' da lista */
void remKey(linkedList * LL, const char * key);

/* remove ultimo */
void remLast(linkedList * LL );

void initialize(linkedList * LL );

void printList(linkedList * LL);

void printHL(linkedList * LL);
