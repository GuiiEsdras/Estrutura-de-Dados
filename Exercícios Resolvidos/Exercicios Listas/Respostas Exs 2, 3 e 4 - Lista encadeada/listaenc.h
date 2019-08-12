#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

typedef struct {
    int tamanho;
    node *begin;
} list;


list* createList();

void add(list *l, int v);

void printList(const list *l);

int isEmpty(const list *l);

void removeBack(list *l);

int size(const list *l);


int hasElement(const list *l, int v);

int insertPosition(list *l, int v, int pos);

int removePosition(list *l, int pos);

int removeElement(list *l, int v);

int get(const list *l, int pos, int *vret);


int clear(list* l);
