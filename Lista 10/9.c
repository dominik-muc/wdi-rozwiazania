#include <stdio.h>
#include <stdlib.h>


typedef struct Element{
    int value;
    struct Element* next;
    struct Element* previous;
} Element;

Element* create(int value){
    Element* head = malloc(sizeof(Element));
    head->next = NULL;
    head->previous = NULL;
    head->value = value;
    return head;
}

void push_back(Element** head, int value){
    Element* iterator = *head;
    if(!iterator) return;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    Element* new = malloc(sizeof(Element));
    new->previous = iterator;
    new->next = NULL;
    new->value = value;
    iterator->next = new;
}

int pop_back(Element** head){
    Element* iterator = *head;
    if(!iterator) return 0;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    (iterator->previous)->next = NULL;
    int value = iterator->value;
    free(iterator);
    return value;
}

int pop_front(Element** head){
    if(!(*head)) return 0;
    Element* new_head = (*head)->next;
    if(!new_head){
        int value = (*head)->value;
        free(*head);
        *head = NULL;
        return value;
    }
    new_head->previous = NULL;
    int value = (*head)->value;
    free(*head);
    *head = new_head;
    return value;
}

int main(){

}