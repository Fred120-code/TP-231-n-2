#include <stdio.h>
#include "dlist.h"

int main() {
    List maListe = new_list();

    printf("=== Insertion en tête ===\n");
    maListe = insert_head(maListe, 3);
    maListe = insert_head(maListe, 2);
    maListe = insert_head(maListe, 1);
    printf_list(maListe);

    printf("\n=== Insertion en queue ===\n");
    maListe = insert_tail(maListe, 4);
    maListe = insert_tail(maListe, 5);
    printf_list(maListe); 

    return 0;
}
