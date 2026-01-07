#ifndef _LIST_H
#define _LIST_H

typedef enum{
    false,
    true
}Bool;


// sturcture d'un element de la liste
typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *List;


//prototypes des fonctions
List new_list(void);
Bool is_empty(List li);
List delete_firt_element(List li);
void found_num(List li, int x);
List add_element(List li, int x);
void print_list(List li);

#endif