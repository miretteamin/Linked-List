#include <stdio.h>
#include <stdlib.h>

#define NULL   ((void*)(0))

typedef struct stacknode
{
    int entry;
    struct stacknode* next;
}StackNode;

typedef struct node
{
    StackNode* top;
}Stack;

void create_LinkedList(Stack* ps)
{
    ps->top = NULL;
}

void push_node(int data, Stack* ps)
{
    StackNode* pn = (StackNode*)malloc(sizeof(StackNode));
    pn->entry = data;
    pn->next = ps->top;
    ps->top = pn;
}

void pop_linkedlist(int *data, Stack* ps)
{
    StackNode* pn;
    *data = ps->top->entry;
    pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
}

int main()
{
    int*data;
    Stack st1;
    create_LinkedList(&st1);
    push_node(10,&st1);
    pop_linkedlist(&data,&st1);
    printf("%d",data);
    return 0;
}
