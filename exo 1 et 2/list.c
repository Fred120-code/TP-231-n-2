#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List new_list(void)
{
    return NULL;
}

// fonction qui renvoie "true" si la liste est vide et "false" si non
Bool is_empty_list(List li)
{
    return (li == NULL) ? true : false;
}

// permet d'afficher la liste
void printf_list(List li)
{
    if (is_empty_list(li))
    {
        printf("Rien à afficher, la liste est vide\n");
        return;
    }
    while (li != NULL)
    {
        printf("[%d] -> ", li->value);
        li = li->next;
    }
    printf("\n");
}

// ajouter un element dans la liste triée
List insert_sorted(List li, int x)
{
    ListElement *element;
    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        fprintf(stderr, "Erreur: probleme allocation dynamique\n");
        exit(EXIT_FAILURE);
    }

    element->value = x;

    if (is_empty_list(li) || x < li->value)
    {
        element->next = li; // l'ancien debut devient le suivant
        return element;
    }

    ListElement *courant = li;
    while (courant->next != NULL && courant->next->value < x)
    {
        courant = courant->next;
    }

    // insertion après "courant"
    element->next = courant->next;
    courant->next = element;

    return li;
}

// supprimer toutes les occurrences d'un élément dans une liste
List del_ele_list(List li, int x)
{
    ListElement *tmp;     // pointeur temporaire pour libérer
    ListElement *courant; // pointeur pour parcourir

    // Cas 1 : supprimer au début (la tête peut contenir x)
    while (li != NULL && li->value == x)
    {
        tmp = li;      // sauvegarder l'ancien début
        li = li->next; // avancer la tête
        free(tmp);     // libérer l'élément supprimé
    }

    // Si la liste est vide après suppression
    if (li == NULL)
        return NULL;

    // Cas 2 : parcourir le reste de la liste
    courant = li;
    while (courant->next != NULL)
    {
        if (courant->next->value == x)
        {
            tmp = courant->next;                 // sauvegarde du nœud à supprimer
            courant->next = courant->next->next; // sauter le nœud
            free(tmp);                           // libération
        }
        else
        {
            courant = courant->next; // avancer seulement si pas de suppression
        }
    }

    return li; // on retourne toujours la tête mise à jour
}
