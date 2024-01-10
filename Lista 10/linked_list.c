#include <stdlib.h>
#include <stdio.h>

typedef struct Element{
    int value;
    struct Element* next;
} Element;

Element* create(int value){
    Element* head = (Element*)malloc(sizeof(Element));
    head->value = value;
    head->next = NULL;
    return head;
}

void push(Element** head, int value){
    Element* iterator = *head;
    while(iterator->next != NULL) iterator = iterator->next;
    iterator->next = create(value);
}

void append(Element** head, Element* tail){
    if(*head == NULL) return;
    Element* iterator = *head;
    while(iterator->next != NULL) iterator = iterator->next;
    iterator->next = tail;
}

int pop(Element** head){
    if(*head == NULL) return 0;

    Element* iterator = *head;
    Element* previous = NULL;
    while(iterator->next != NULL){
        previous = iterator;
        iterator = iterator->next;
    }
    int value = iterator->value;
    free(iterator);
    if(previous == NULL){
        *head = NULL;
        return 0;
    }
    previous->next = NULL;
    return value;
}

void print_list(Element* head){
    if(head == NULL) return;
    while(head->next != NULL){
        printf("%i ", head->value);
        head = head->next;
    }
    printf("%i\n", head->value);
}

void delete(Element** head, int value){
    Element* iterator = *head;
    Element* previous = NULL;
    while(iterator != NULL){
        if(iterator->value == value){
            if(previous == NULL){
                *head = iterator->next;
                free(iterator);
                iterator = *head;
                continue;
            }
            if(iterator->next == NULL){
                free(iterator);
                previous->next = NULL;
                return;
            }
            previous->next = iterator->next;
            free(iterator);
            iterator = previous->next;   
            continue;   
        }
        previous = iterator;
        iterator = iterator->next;
    }
}

void print_back(Element* iterator){
    if(iterator == NULL) return;
    print_back(iterator->next);
    printf("%i ", iterator->value);
}

void reverse(Element** head) {
    Element *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    *head = prev; // Update the head to point to the new start of the reversed list
}

void free_list(Element** head){
    if(*head == NULL) return;
    free_list(&((*head)->next));
    free(*head);
    *head = NULL;
}

int main(){
    Element* head = create(69);
    push(&head, 7);
    push(&head, 52);
    push(&head, 7);
    push(&head, 14);
    delete(&head, 7);
    print_list(head);
    reverse(&head);
    print_list(head);
    return 0;
}