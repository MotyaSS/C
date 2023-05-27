#include "cw8.h"

// LINKED LIST IMPLEMENTATION



void InitLinkedList(LinkedList *L) {
    L->Forward = NULL;
}

void AddByIndexLinkedList(LinkedList *L, ComplexNumber value, int index) {

    if (index < 0) {
        printf("Incorrect index!\n");
        return;
    }

    if (IsEmptyLinkedList(L)) {
        printf("List is Empty!\n");
        return;
    }

    Node *current_node = L->Forward;

    for (int i = 0; i <= index; i++) {
        if (current_node == NULL) {
            printf("Incorrect index");
            return;
        }
        current_node = current_node->Next;
    }

    //попали на нулевую ноду = следующего элемента нет; значит нужно добавить в конец
    if (current_node == NULL) {
        PushBackLinkedList(L, value);
        return;
    }

    Node *next_node = current_node->Next;

    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->Next = next_node;
    new_node->Previous = current_node;
    new_node->value = value;

    current_node->Next = new_node;
    next_node->Previous = new_node;
}

void PushForwardLinkedList(LinkedList *L, ComplexNumber value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->Next = NULL;
    node->Previous = NULL;
    node->value = value;

    if (IsEmptyLinkedList(L)) {
        L->Forward = node;
        return;
    }

    Node *temp = L->Forward;
    temp->Previous = node;
    node->Next = temp;
    L->Forward = node;
}

void PushBackLinkedList(LinkedList *L, ComplexNumber value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->Next = NULL;
    node->Previous = NULL;
    node->value = value;

    if (IsEmptyLinkedList(L)) {
        L->Forward = node;
        return;
    }

    Node *temp = L->Forward;
    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    temp->Next = node;
    node->Previous = temp;
}

void DeleteElementByIndex(LinkedList *L, int index) {
    if (index < 0) {
        printf("Incorrect Index!\n");
        return;
    }

    if (IsEmptyLinkedList(L)) {
        printf("List is empty!\n");
        return;
    }

    Node *node = L->Forward;
    for (int i = 0; i < index; i++) {
        node = node->Next;
        if (node == NULL) {
            printf("Incorrect Index!\n");
            return;
        }
    }
    if (L->Forward == node) {
        L->Forward = node->Next;
    }
    if (node->Previous != NULL) {
        node->Previous->Next = node->Next;
    }
    if (node->Next != NULL) {
        node->Next->Previous = node->Previous;
    }
    free(node);
}

ComplexNumber GetElementByIndex(LinkedList *L, int index) {
    ComplexNumber c = {.ReNum = 0, .ImNum = 0};
    if (IsEmptyLinkedList(L)) {
        printf("List is empty!\n");
        return c;
    }

    Node *node = L->Forward;
    for (int i = 0; i < index; i++) {
        if (node == NULL) {
            printf("Incorrect Index!\n");
            return c;
        }
        node = node->Next;
    }
    return node->value;
}

bool IsEmptyLinkedList(LinkedList *L) {
    return L->Forward == NULL;
}

int GetCountLinkedList(LinkedList *L) {
    Node *node = L->Forward;
    int iterator = 0;
    while (node != NULL) {
        node = node->Next;
        iterator++;
    }

    return iterator;
}

void PrintLinkedList(LinkedList *L) {
    if (IsEmptyLinkedList(L)) {
        printf("List is Empty!\n");
    }

    Node *node = L->Forward;
    while (node != NULL) {
        if (node->Next == NULL) {
            PrintComplex(node->value);
            break;
        }
        PrintComplex(node->value);
        printf("; ");

        node = node->Next;
    }
    putchar('\n');
}

void PrintComplex(ComplexNumber c) {
    printf("%.1f %.1fi", c.ReNum, c.ImNum);
}

void DeleteLinkedList(LinkedList *L) {
    if (L->Forward == NULL) {
        printf("List is Empty!\n");
        return;
    }

    Node *node = L->Forward;

    while (node != NULL) {
        Node *temp = node;
        node = node->Next;
        free(temp);
    }

    L->Forward = NULL;
}

ComplexNumber EnterComplex() {
    ComplexNumber c;
    scanf_s("%f%f", &c.ReNum, &c.ImNum);
    return c;
}