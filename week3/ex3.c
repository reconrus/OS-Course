#include <stdio.h>
#include <malloc.h>
#include <stddef.h>

typedef	struct _node
{
    int data;
    struct _node* next;
} Node;

typedef struct{
    Node* head;
    size_t size;
} LinkedList;

LinkedList* create_list(){
    LinkedList* l = (LinkedList*) malloc(sizeof(LinkedList));
    l -> head = (Node*) malloc(sizeof(Node));
    l -> head -> next = NULL;
    l -> size = 0;
    return l;
}

void insert_node(LinkedList* l, int data){

    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;

    Node* current = l -> head;

    while(current -> next != NULL){
        current = current -> next;
    }

    current -> next = (Node*) malloc(sizeof(Node));
    current -> next -> next = NULL;
    current -> next -> data = data;

    l -> size++;

}

void print_list(LinkedList* l){
    Node* current = l -> head -> next;
    while(current != NULL){
        printf("%d ", current -> data);
        current = current -> next;
    }
}

void delete_node(LinkedList* l, int index){
    if(index < l->size) {
        Node *current = l -> head;

        for(int i = 0; i < index; i++){
            current = current -> next;
        }
        Node* next = current -> next -> next;
        free(current->next);
        current->next = next;
    }
    else printf("\n%s\n", "Out of bounds");
}
