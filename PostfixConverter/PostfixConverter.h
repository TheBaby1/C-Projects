#ifndef POSTFIX_CONVERTER
#define POSTFIX_CONVERTER

#include <stdbool.h>

#define SIZE 50
#define EMPTY '\0'

typedef char String[SIZE];

typedef struct node {
	char operation;
	struct node *next;
} StackLinkedList;

typedef struct {
	String postfix;
	int count;
} Postfix;

StackLinkedList *createStack();
void initializeStack(StackLinkedList **head);

void convertString(Postfix *P, String infix, StackLinkedList **head);
void push(StackLinkedList **head, char ch);
char pop(StackLinkedList **head);
bool isEmpty(StackLinkedList *head);
char peek(StackLinkedList *head);

void insertPostfix(Postfix *P, char ch);
int decidePrecedence(char ch);

#endif
