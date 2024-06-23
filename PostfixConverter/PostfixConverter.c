#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "PostfixConverter.h"

StackLinkedList *createStack(){
	
	StackLinkedList *head;
	initializeStack(&head);
	
	return head;
}

void initializeStack(StackLinkedList **head){
	
	*head = NULL;
}

void initializePostfix(Postfix *P){
	
	P->count = 0;
	int i;
	
	for (i = 0; i < SIZE; i++){
		P->postfix[i] = EMPTY;
	}
}

void convertString(Postfix *P, String infix, StackLinkedList **head) {
	
    int i = 0;
    int value, value2;
    char chValue;
    
    while (infix[i] != '\0') {
        char ch = infix[i];

        if (ch == ' ') {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            insertPostfix(P, ch);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {

            if (isEmpty(*head)) {
                push(head, ch);
            } else {
                chValue = peek(*head); 
                value = decidePrecedence(ch); 
                value2 = decidePrecedence(chValue); 

                if (value < value2 || value == value2) {
                	while (!isEmpty(*head)){
                		chValue = pop(head);
                    	insertPostfix(P, chValue);
					}
					push(head, ch);
                } else {
                    push(head, ch);
                }
            }
        } else {
            printf("Unknown character: %c\n", ch);
        }

        i++;
    }
    
    while (!isEmpty(*head)){
    	chValue = pop(head);
    	insertPostfix(P, chValue);
	}
	
}


void push(StackLinkedList **head, char ch){
	
	StackLinkedList *newNode = malloc(sizeof(StackLinkedList));
	
	newNode->operation = ch;
	
	if (isEmpty(*head)){
		newNode->next = NULL;
		*head = newNode;
	} else {
		newNode->next = *head;
		*head = newNode;
	}
}

char pop(StackLinkedList **head){
	
	StackLinkedList *temp = *head;
	char value;
	
	if (!isEmpty(*head)){
		value = temp->operation;
		*head = temp->next;
		free(temp);
	}
	
	return value;
}

char peek(StackLinkedList *head){
	
	return (!isEmpty(head)) ? head->operation : 0;
}

bool isEmpty(StackLinkedList *head){
	
	return (head == NULL);
}

void insertPostfix(Postfix *P, char ch){
	
	P->postfix[P->count] = ch;
	P->count++;
}

int decidePrecedence(char ch){
	
	switch (ch){
		case '+':
		case '-':
			return 1;
		case '*':
        case '/':
            return 2; 
        case '(':
        case ')':
            return 3;  
        default:
            return 0;  
	}
}

void displayPostfix(Postfix P){
	
	int i;
	
	for (i = 0; i < SIZE; i++){
		if (P.postfix[i] != EMPTY){
			printf("%c ", P.postfix[i]);
		}
	}
}
