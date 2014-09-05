#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct List {
    struct Node *head;
};

// push to beginning of linked list
struct Node *push(struct List *list, int val) {
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("malloc didn't work :(");
        return NULL;
    }

    new_node->val = val;
    new_node->next = list->head;
    list->head = new_node;

    return new_node;
} 

void pushTail(struct List *list, int val) {
    struct Node * new_node = (struct Node *)(malloc(sizeof(struct Node)));

    new_node->val = val;
    new_node->next = NULL;

    if (new_node == NULL) {
        printf("malloc didn't work :(");
    }

    struct Node *node = list->head;

    while (node->next != NULL) {
        //printf("%d\n", node->val);
        node = node->next;
    }

    //printf("%d\n", node->val);

    node->next = new_node;
}

// traverse and print linked list
void printList(struct List *list) {
    struct Node *current = list->head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

// reverse the linked list
void reverse(struct List *list) {
    struct Node *current = list->head;
    struct Node *prev = NULL;
    struct Node *temp = list->head;

    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    list->head = prev;
}

void delete(struct List *list, int d) {
    
}

// init empty list
static inline void initList(struct List *list)
{
    list->head = 0;
}

int main() {

    // initialize list
    struct List list;
    // & turns a value into a pointer
    initList(&list);

    int i;

    for (i = 0; i < 10; i++) {
        if (push(&list, i) == NULL) {
            printf("oh no :(\n");
        }
    }

    pushTail(&list, 21);

    reverse(&list);

    printList(&list);

    return 0;
}
