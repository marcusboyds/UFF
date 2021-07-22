#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int printarLista(struct node* head){
    while (head != NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
}

inverterLista(struct node* head){
    
    struct node* temp;
    temp = head;
    
    while (temp != NULL)
    {
        temp->next->next = temp;
        temp = temp->next;
    }
    
}

int main(){

    struct node *head;
    struct node *first, *second, *third, *fourth;

    first = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
    fourth = malloc(sizeof(struct node));

    head = first;

    //Setar informação.
    first->data = 1;
    second->data = 3;
    third->data = 4;
    fourth->data = 5;

    //Conectar os nós.
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    printarLista(head);
    inverterLista(head);
    printarLista(head);
    return 0;
}