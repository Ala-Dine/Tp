 #include <stdio.h>
#include <stdlib.h>

// Definition of the list element structure
typedef struct element {
    int val;
    struct element *next;
} element;

// Function prototypes
element* createList();
element* loadList(int* arr, int n);
void displayList(element* head);
element* removeLast(element* head);
element* addAtBeginning(element* head, int val);
void emptyList(element* head);


int main() {
    int arr[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};
    element* list = createList();
    element* L = loadList(arr, 10);
    displayList(L);
    element* L1 = removeLast(L);
    displayList(L1);
    element* L2 = addAtBeginning(L1, 40);
    displayList(L2);
    emptyList(L2);
    return 0;
}

// Function to create an empty list
element* createList() {
    return NULL;
}

// Function to load a list from an array
element* loadList(int* arr, int n) {
    element* head = NULL;
    element* temp = NULL;
    for (int i = 0; i < n; i++) {
        element* newNode = (element*)malloc(sizeof(element));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

// Function to display the elements of the list
void displayList(element* head) {
    element* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to remove the last element of the list
element* removeLast(element* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    element* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to add an element at the beginning of the list
element* addAtBeginning(element* head, int val) {
    element* newNode = (element*)malloc(sizeof(element));
    newNode->val = val;
    newNode->next = head;
    return newNode;
}

// Function to empty the list and print "la liste est vide"
void emptyList(element* head) {
    element* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("la liste est vide\n");
}
