#include <stdio.h>
#include <stdlib.h>

#include "PostfixConverter.h"

int main(){
	
	StackLinkedList *head = createStack();
	Postfix P;
	String input = "3 + 2 * 5 - 4 * 8 / 2 + 2";
	initializePostfix(&P);
	
	printf("Converting: 3 + 2 * 5 - 4 * 8 / 2 + 2: \n");
	convertString(&P, input, &head);
	
	displayPostfix(P);
	
	return 0;
}
