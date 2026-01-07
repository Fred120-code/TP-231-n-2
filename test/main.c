#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    List ma_list = new_list();
    int n,i = 0,nbre;

    printf("conbien de nombre voulez-vous entrer : ");
    scanf("%d",&n);

    while( nbre != -1 && i < n)
    {
        printf("nombre %d:",i+1);
        scanf("%d",&nbre);
            if (nbre != -1)
            {
                ma_list = add_element(ma_list,nbre);
            }
            
        i++;
    }
        printf("contenu de la liste  apres insertion des %d element(s) :\n", n);
        print_list(ma_list);

        found_num(ma_list, 3);
        delete_firt_element(ma_list);

        printf("contenu de la liste  apres la suppression de la tete:\n", n);
        print_list(ma_list);
        return 0;
}