#ifndef _LIST_CIRCULAR_DBL_H_
#define _LIST_CIRCULAR_DBL_H_

typedef enum{
    false,
    true
}Bool;

//structure d'une element de la liste

typedef struct ListElement
{
   int value;
   struct ListElement *next;
   struct ListElement *prev;
}ListElement, *List;


//prototypes des fonctions
List new_list(void);
Bool is_empty_list(List li);
List insert_head(List li, int x);
List insert_tail(List li, int x);
void printf_list(List li);

#endif