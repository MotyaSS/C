#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// LINKED LIST IMPLEMENTATION

typedef struct {
    float ReNum;
    float ImNum;
} ComplexNumber;

typedef struct Node {
    ComplexNumber value;
    struct Node *Next;
    struct Node *Previous;
} Node;

typedef struct {
    Node *Forward;
} LinkedList;
// ( )->( )->( )->( )->( )
//  ^ Forward           ^ Back

void InitLinkedList(LinkedList *L);

void PrintLinkedList(LinkedList *L);

void PrintComplex(ComplexNumber c);

ComplexNumber EnterComplex();

//Вставка после индекса указанного элемента
void AddByIndexLinkedList(LinkedList *L, ComplexNumber value, int index);

void PushBackLinkedList(LinkedList *L, ComplexNumber value);

void PushForwardLinkedList(LinkedList *L, ComplexNumber value);

void DeleteElementByIndex(LinkedList *L, int index);

ComplexNumber GetElementByIndex(LinkedList *L, int index);

int GetCountLinkedList(LinkedList *L);

bool IsEmptyLinkedList(LinkedList *L);

void DeleteLinkedList(LinkedList* L);