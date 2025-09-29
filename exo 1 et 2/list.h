#ifndef _LIST_H_
#define _LIST_H_

typedef enum{
    false,
    true
}Bool;

//structure d'un element de la liste
typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *List;

//prototypes des fonctions
List new_list(void);
Bool is_empty_list(List li);
List del_ele_list(List li, int x);
List insert_sorted(List li, int x);
void printf_list(List li);

#endif