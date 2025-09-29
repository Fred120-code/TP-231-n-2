#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

// creer une liste vide
List new_list(void)
{
    return NULL;
}

// fonction qui renvoie "true" si la liste est vide et "false" si non
Bool is_empty_list(List li)
{
    return (li == NULL) ? true : false;
}

// inserer en tete de liste
List insert_head(List li, int x)
{
    ListElement *element = malloc(sizeof(*element));
    if (!element)
    {
        fprintf(stderr, "Erreur allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;

    if (is_empty_list(li))
    {
        element->next = element->prev = element; // seul nœud pointe sur lui-même
        return element;
    }

    ListElement *tail = li->prev; // le dernier élément

    element->next = li;
    element->prev = tail;
    tail->next = element;
    li->prev = element;

    return element; // nouvelle tête
}

//insertion en queue
List insert_tail(List li, int x){
     ListElement *element = malloc(sizeof(*element));
    if (!element) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;

    if (is_empty_list(li)) {
        element->next = element->prev = element; // seul nœud
        return element;
    }

    ListElement *tail = li->prev;
    element->next = li;
    element->prev = tail;
    tail->next = element;
    li->prev = element;

    return li; 
}

// affiche la liste 
void printf_list(List li) {
    if (is_empty_list(li)) {
        printf("Liste vide\n");
        return;
    }

    ListElement *courant = li;
    do {
        printf("[%d] ", courant->value);
        courant = courant->next;
    } while (courant != li);
    printf("\n");
}
