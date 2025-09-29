#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

List new_list(void) {
    return NULL; // liste vide = NULL
}

Bool is_empty_list(List li) {
    return li == NULL;
}

//Afficher la liste de gauche à droite
void printf_list(List li){
    if (is_empty_list(li))
    {
        printf("Rien à afficher, la liste est vide\n");
        return;
    }
    List tmp = li;
    while (tmp != NULL)
    {
        printf("[%d]", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

//Inserer un element dans la liste en gardant l'ordre croissant
List insert_sorted(List li, int x){
    ListElement *element = malloc(sizeof(*element));
    if (!element)
    {
        fprintf(stderr, "Erreur: probleme allocation");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    element->next = element->prev = NULL;

    // Liste vide ou insertion en tête
    if (is_empty_list(li) || x < li->value) {
        element->next = li;
        if (li != NULL)
            li->prev = element;
        return element; // nouvelle tête
    }

    // Parcours pour trouver l'emplacement
    ListElement *courant = li;
    while (courant->next != NULL && courant->next->value < x) {
        courant = courant->next;
    }

    // Insertion après "courant"
    element->next = courant->next;
    element->prev = courant;
    if (courant->next != NULL)
        courant->next->prev = element;
    courant->next = element;

    return li; // tête inchangée
}


// Supprime toutes les occurrences de x dans la liste
List del_ele_list(List li, int x) {
    if (is_empty_list(li))
        return NULL;

    ListElement *courant = li;
    while (courant != NULL) {
        if (courant->value == x) {
            ListElement *tmp = courant;
            if (courant->prev != NULL)
                courant->prev->next = courant->next;
            else
                li = courant->next; // on supprime la tête

            if (courant->next != NULL)
                courant->next->prev = courant->prev;

            courant = courant->next;
            free(tmp);
        } else {
            courant = courant->next;
        }
    }
    return li;
}



// Libère toute la mémoire de la liste
void free_list(List li) {
    ListElement *tmp;
    while (li != NULL) {
        tmp = li;
        li = li->next;
        free(tmp);
    }
}
