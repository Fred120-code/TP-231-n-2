#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List new_list(void){
    return NULL;
}

Bool is_empty(List li){
    return (li == NULL) ? true : false;
}

void print_list(List li){

    if (is_empty(li))
    {
        printf("La liiste est vide\n");
        return;
    }

    while (li != NULL)
    {
        printf("[%d]->", li->value);
        li = li->next;
    }
    printf("\n");
    
}

List add_element(List li, int x){
    ListElement *element;
    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        printf("Erreur de l'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = li;

    return element;
    
}

void found_num(List li, int x){
    int n = 1;
    if (is_empty(li))
    {
        printf("La liste est vide, la valeur %d n'y est pas.\n", x);
        return;
    }

    ListElement *courant = li;
    Bool isFound = false;

    while (courant != NULL)
    {
        if (courant->value == x)
        {
            isFound = true;
            break;    
        }
        n++;
        courant = courant->next;
    }

    if (isFound == true)
    {
        printf("La valeur %d a ete trouvee dans la liste.\n", x);
        printf("elle est à la position %d\n",n);
    }
    else
    {
        printf("La valeur %d n'a pas ete trouvee dans la liste.\n", x);
    }
}

List delete_firt_element(List li){
    if (is_empty(li))
    {
        printf("la liste est vide\n");
        return li;
    }

    ListElement *element;
    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        fprintf(stderr,"Erreur lors de l'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    
    element = li->next;
    free(li);
    li = NULL;

    return element;
}