#include <stdio.h>
#include <stdlib.h>

typedef struct _tno{
    int key;
    struct _tno *next;
} tno;

enum boolean{False, True};

void init(tno *);
int empty(tno *);
void push(tno *, int);
void pop(tno *);
void print(tno*);


int main(int argc, char *argv[])
{
    tno *stack;
    stack = (tno *)malloc(sizeof(tno));
    if(!stack){
        puts("Erro de alocação!");
        exit(1);
    }

    init(stack);
    push(stack, 12);
    push(stack, 20);
    push(stack, 30);
    printf("Hello World!\n");

    printf("%d\n", stack->next->key);
    printf("%d\n", stack->next->next->key);
    printf("%d\n", stack->next->next->next->key);
    pop(stack);
    printf("%d\n", stack->next->key);
    printf("%d\n", stack->next->next->key);
    return 0;
}

void init(tno *stack){
    stack->key = (int)NULL;
    stack->next = NULL;
    printf("%d dentro init\n", stack->key);
}

int empty(tno *stack){
    if(stack->next == NULL && stack->key == (int)NULL)
        return True;
    else
        return False;
}

void push(tno *stack, int value){
    tno *temp;
    temp = (tno *)malloc(sizeof(tno));
    if(!temp){
        puts("Erro de alocação!");
        exit(1);
    }

    if(empty(stack)){
        temp->key = value;
        temp->next = NULL;
        stack->next = temp;
    }
    else{
        temp->key = value;
        temp->next = stack->next;
        stack->next = temp;
    }
}


void pop(tno* stack){
    if(empty(stack))
        return;
    else{
        tno* temp;
        temp = (tno*)malloc(sizeof(tno));
        if(!temp){
            puts("Erro de alocação!");
            exit(1);
        }
        stack->next = stack->next->next;
    }
}
