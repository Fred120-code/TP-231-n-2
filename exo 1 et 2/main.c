#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    List maListe = new_list();

    printf("=== Test d'insertion triée ===\n");
    maListe = insert_sorted(maListe, 1);
    maListe = insert_sorted(maListe, 3);
    maListe = insert_sorted(maListe, 2);
    maListe = insert_sorted(maListe, 5);
    maListe = insert_sorted(maListe, 1); // j'ai ajouté des doublons pour tester la Suppression de toutes les occurrences de 1
    maListe = insert_sorted(maListe, 1);


    printf("Contenu de la liste avant insertions de 4:\n");
    printf_list(maListe);

    maListe = insert_sorted(maListe, 4);
    printf("Contenu de la liste apres insertions de 4:\n");
    printf_list(maListe);

    printf("\n=== Test suppression ===\n");
    printf("Suppression de toutes les occurrences de 1...\n");
    maListe = del_ele_list(maListe, 1);
    printf("Liste apres suppression :\n");
    printf_list(maListe); 

    return 0;
}