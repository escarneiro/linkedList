/*

    Linked list - programa demo para lista encadeada em C
    @author: Eder Carneiro

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

int main(int argc, char ** argv){

    linkedList LL;
    initialize(&LL);

    add(&LL,"dois",2);
    add(&LL,"quatro",4);
    add(&LL,"oito",8);
    add(&LL,"dezesseis",16);
    add(&LL,"trintedois",32);



    printf("Lista inicial:\n");
    printList(&LL);

    listElement * tt=search(&LL,"quatro");
    printf("\nBusca por 'quatro': %s : %d\n",tt->key,tt->value);

    printf("\nRemoveu ultimo\n");
    remLast(&LL);
    printList(&LL);

    remKey(&LL,"quatro");
    printf("\nRemoveu o 'quatro' \n");
    printList(&LL);

    listElement * ultimo = peek(&LL);

    printf("\nUltimo elemento: {%s : %d}",ultimo->key,ultimo->value);



}
