#include <stdio.h>
#include <stdlib.h>

#include "list.h"

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

// insertion en tete
List insert_head(List li, int x)
{
    ListElement *element = malloc(sizeof(*element));

    if (!element)
    {
        fprintf(stderr, "Erreur: probleme lors de l'allocation\n");
        exit(EXIT_FAILURE);
    }

    element->value = x;

    if (is_empty_list(li))
    {
        element->next = element; // le noeud pointe sur lui meme
        return element;
    }

    // on trouve la queue pour mettre à jour son next
    ListElement *queue = li;
    while (queue->next != li)
    {
        queue = queue->next;
    }

    element->next = li;
    queue->next = element;

    return element;
}

// insertion en queue
List insert_tail(List li, int x)
{
    ListElement *element = malloc(sizeof(*element));

    if (!element)
    {
        fprintf(stderr, "Erreur: probleme lors de l'allocation\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    if (is_empty_list(li))
    {
        element->next = element; // le noeud pointe sur lui meme
        return element;
    }

    // on trouve la queue 
    ListElement *queue = li;
    while (queue->next != li)
    {
        queue = queue->next;
    }

    queue->next = element;
    element->next = li;

    return li;
}

//affichage de la liste
void printf_list(List li)
{
    if (is_empty_list(li))
    {
        printf("Liste vide\n");
        return;
    }

    ListElement *courant = li;
    do
    {
        printf("[%d]", courant->value);
        courant = courant->next;
    } while (courant != li);
    
    printf("\n");
}
